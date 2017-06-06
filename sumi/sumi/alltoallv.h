/**
Copyright 2009-2017 National Technology and Engineering Solutions of Sandia, 
LLC (NTESS).  Under the terms of Contract DE-NA-0003525, the U.S.  Government 
retains certain rights in this software.

Sandia National Laboratories is a multimission laboratory managed and operated
by National Technology and Engineering Solutions of Sandia, LLC., a wholly 
owned subsidiary of Honeywell International, Inc., for the U.S. Department of 
Energy's National Nuclear Security Administration under contract DE-NA0003525.

Copyright (c) 2009-2017, NTESS

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.

    * Neither the name of Sandia Corporation nor the names of its
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

#ifndef ALLTOALLV_H
#define ALLTOALLV_H

#include <sumi/collective.h>
#include <sumi/collective_actor.h>
#include <sumi/collective_message.h>
#include <sumi/comm_functions.h>

namespace sumi {

class direct_alltoallv_actor :
  public bruck_actor
{

 public:
  direct_alltoallv_actor(int* send_counts, int* recv_counts) :
    send_counts_(send_counts), recv_counts_(recv_counts) {}

  std::string to_string() const override {
    return "bruck all-to-allv actor";
  }

 protected:
  void finalize() override;

  void finalize_buffers() override;

  void init_buffers(void *dst, void *src) override;

  void init_dag() override;

  void buffer_action(void *dst_buffer, void *msg_buffer, action* ac) override;

 private:
  void add_action(
    const std::vector<action*>& actions,
    int stride_direction,
    int num_initial,
    int stride);

  int midpoint_;
  int* send_counts_;
  int* recv_counts_;
  int total_recv_size_;
  int total_send_size_;
};

class direct_alltoallv_collective :
  public dag_collective
{
  FactoryRegister("bruck_alltoall", dag_collective, direct_alltoallv_collective)
 public:
  std::string to_string() const override {
    return "all-to-all";
  }

  dag_collective_actor* new_actor() const override {
    return new direct_alltoallv_actor(send_counts_, recv_counts_);
  }

  dag_collective* clone() const override {
    return new direct_alltoallv_collective;
  }

  void init_send_counts(int* nelems) override {
    send_counts_ = nelems;
  }

  void init_recv_counts(int* nelems) override {
    recv_counts_ = nelems;
  }

 private:
  int* send_counts_;
  int* recv_counts_;

};

}

#endif // ALLGATHER_H
