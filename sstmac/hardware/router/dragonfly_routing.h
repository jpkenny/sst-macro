/**
Copyright 2009-2020 National Technology and Engineering Solutions of Sandia,
LLC (NTESS).  Under the terms of Contract DE-NA-0003525, the U.S.  Government
retains certain rights in this software.

Sandia National Laboratories is a multimission laboratory managed and operated
by National Technology and Engineering Solutions of Sandia, LLC., a wholly
owned subsidiary of Honeywell International, Inc., for the U.S. Department of
Energy's National Nuclear Security Administration under contract DE-NA0003525.

Copyright (c) 2009-2020, NTESS

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.

    * Neither the name of the copyright holder nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Questions? Contact sst-macro-help@sandia.gov
*/

#include <sstmac/hardware/router/router.h>
#include <sstmac/hardware/topology/dragonfly.h>

namespace sstmac {
namespace hw {

class DragonflyMinimalRouter : public Router
{
 public:
  SST_ELI_REGISTER_DERIVED(
    Router,
    DragonflyMinimalRouter,
    "macro",
    "dragonfly_minimal",
    SST_ELI_ELEMENT_VERSION(1,0,0),
    "router implementing minimal dragonfly")

  DragonflyMinimalRouter(SST::Params& params, Topology* top,
                         NetworkSwitch* netsw);

  ~DragonflyMinimalRouter() override {}

  std::string toString() const override {
    return "dragonfly minimal router";
  }

  void route(Packet* pkt) override;

  int numVC() const override {
    return 2;
  }

  void failPort(int port) override
  {
    if (port < dfly_->a())
      spkt_abort_printf("DragonflyMinimalRouter: cannot fail intragroup port %d", port);
    failed_outports_.insert(port);
  }

  void try_outport(SwitchId ej_addr, int dstG, int& outport);

  void routeToSwitch(Packet* pkt, SwitchId ej_addr);

 protected:

  struct header : public Packet::Header {
    uint8_t num_group_hops : 2;
    uint8_t num_hops : 4;
  };

  Dragonfly* dfly_;

  std::vector<std::vector<int>> group_ports_;
  std::vector<int> group_port_rotaters_;

  bool static_route_;

  int my_g_;
  int my_a_;

  std::unordered_set<int> failed_outports_;
};

class DragonflyValiantRouter : public DragonflyMinimalRouter {
 public:
  SST_ELI_REGISTER_DERIVED(
    Router,
    DragonflyValiantRouter,
    "macro",
    "dragonfly_valiant",
    SST_ELI_ELEMENT_VERSION(1,0,0),
    "router implementing valiant dragonfly")

  static const char initial_stage = 0;
  static const char valiant_stage = 1;
  static const char final_stage = 2;

  struct header : public DragonflyMinimalRouter::header {
    uint8_t stage_number : 3;
    uint32_t dest_switch : 24;
  };

  DragonflyValiantRouter(SST::Params& params, Topology *top,
                         NetworkSwitch *netsw);

  std::string toString() const override {
    return "dragonfly valiant";
  }

  int numVC() const override {
    return 6;
  }

  void checkValiantInterGroup(Packet* pkt, int dst_g);

  void checkValiantIntraGroup(Packet* pkt, int dst_a);

  void route(Packet *pkt) override;

 protected:
  std::vector<int> gateway_rotater_; //for non-minimal
  std::vector<std::vector<std::pair<int,int>>> group_gateways_;
};

class DragonflyUGALRouter : public DragonflyValiantRouter {

 public:
  static const char minimal_only_stage = final_stage + 1;

  SST_ELI_REGISTER_DERIVED(
    Router,
    DragonflyUGALRouter,
    "macro",
    "dragonfly_ugal",
    SST_ELI_ELEMENT_VERSION(1,0,0),
    "router implementing UGAL dragonfly")

  DragonflyUGALRouter(SST::Params& params, Topology *top,
                      NetworkSwitch *netsw)
    : DragonflyValiantRouter(params, top, netsw)
  {
    val_threshold_ = params.find<int>("val_threshold", 0);
    vl_queues_ = params.find<bool>("vl_queues", false);
  }

  std::string toString() const override {
    return "dragonfly ugal router";
  }

  int numVC() const override {
    return 6;
  }

  void checkUGALInterGroup(Packet* pkt, int dst_a, int dst_g, char minimal_stage);

  void checkUGALIntraGroup(Packet* pkt, int dst_a, char minimal_stage);

  void route(Packet *pkt) override;

 protected:
  int val_threshold_;
  bool vl_queues_;

};

class DragonflyPARRouter : public DragonflyUGALRouter {
 public:
  SST_ELI_REGISTER_DERIVED(
    Router,
    DragonflyPARRouter,
    "macro",
    "dragonfly_par",
    SST_ELI_ELEMENT_VERSION(1,0,0),
    "router implementing PAR dragonfly")

  std::string toString() const override {
    return "dragonfly PAR router";
  }

  DragonflyPARRouter(SST::Params& params, Topology *top,
                       NetworkSwitch *netsw)
    : DragonflyUGALRouter(params, top, netsw)
  {
  }

  void route(Packet *pkt) override;

};

class DragonflyScatterRouter : public Router {

 public:
  SST_ELI_REGISTER_DERIVED(
    Router,
    DragonflyScatterRouter,
    "macro",
    "dragonfly_scatter",
    SST_ELI_ELEMENT_VERSION(1,0,0),
    "router implementing dragonfly that obliviously scatters traffic")

 protected:
  struct header : public Packet::Header {
    uint8_t num_group_hops : 2;
    uint8_t num_hops : 4;
  };

  static const int max_hops = 3;

  struct destination {
    std::set<int>::iterator rotater;
    std::set<int> ports;

    int nextPort(){
      int port = *rotater; //ports[rotater];
      ++rotater;
      if (rotater == ports.end()){
        rotater = ports.begin();
      }
      return port;
    }

    void init(){
      rotater = ports.begin();
    }

    destination(){}
  };

 public:
  DragonflyScatterRouter(SST::Params& params, Topology* top,
                           NetworkSwitch* netsw);

  void followPathHelper(int sid, int num_hops, int num_group_hops, int port);

  void followPath(int sid, int num_hops, int num_group_hops, int port = -1);

  int numVC() const override {
    return 3;
  }

  std::string toString() const override {
    return "dragonfly scatter router";
  }

  void route(Packet *pkt) override;

 protected:
  Dragonfly* dfly_;

  std::vector<destination> destination_table_[max_hops+1];

  int my_g_;
  int my_a_;
};

class DragonflyRotateRouter : public DragonflyMinimalRouter {
 public:
  SST_ELI_REGISTER_DERIVED(
    Router,
    DragonflyRotateRouter,
    "macro",
    "dragonfly_rotate",
    SST_ELI_ELEMENT_VERSION(1,0,0),
    "router implementing dragonfly that obliviously scatters traffic")

  DragonflyRotateRouter(SST::Params& params, Topology* top,
                        NetworkSwitch* netsw);

  int numVC() const override {
    return 4;
  }

  std::string toString() const override {
    return "dragonfly rotate router";
  }

  void route(Packet *pkt) override;

 private:
  std::set<int>::iterator port_rotater_;
  std::set<int> valid_ports_;
};

}
}
