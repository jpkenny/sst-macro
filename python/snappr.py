# Load module function in Python is changed
# to look for a libmacro.so in LD_LIBRARY_PATH
import sst
import sst.macro

sst.setProgramOption("timebase", "100as")

mtu = "4KB"
small_latency = "1ps"
nic_latency = "50ns"
nic_bandwidth = "1.0GB/s"
link_latency = "100ns"
link_bandwidth = "1.0GB/s"

topo_params = dict(
  name = "dragonfly",
  geometry = "[4,3]",
  h = "6",
  inter_group = "circulant",
  concentration = "4"
)

router_name = "dragonfly_minimal"

system = sst.macro.System(topo_params)
num_switches = system.numSwitches()
num_nodes = system.numNodes()

switches = [None]*num_switches
nodes = [None]*num_nodes

for i in range(num_switches):
  switch = sst.Component("Switch %d" % i, "macro.snappr_switch")
  switch.addParams({
    "router.name" : router_name,
    "credits" : "8KB",
    "id" : i,
    "link.bandwidth" : link_bandwidth,
    "link.latency" : link_latency,
    "link.mtu" : mtu
  })
  switches[i] = switch

for i in range(num_nodes):
  node = sst.Component("Node %d" % i, "macro.simple_node")
  node.addParams({
    "proc.frequency" : "2GHz",
    "app1.name" : "mpi_ping_all",
    "app1.launch_cmd" : "aprun -n 4 -N 1",
    "id" : i,
    "app1.message_size" : "20KB",
    "memory.name" : "snappr",
    "memory.channel_bandwidth" : "1.0GB/s",
    "memory.num_channels" : 8,
    "nic.name" : "snappr",
    "nic.bandwidth" : nic_bandwidth,
    "nic.latency" : link_latency,
    "nic.credits" : "8KB",
    "nic.mtu" : mtu,
    "nic.injection.bandwidth" : nic_bandwidth,
    "nic.injection.latency" : link_latency,
    "nic.injection.credits" : "8KB",
    "nic.injection.mtu" : mtu,
  })
  nodes[i] = node

  #build the NIC
  nic = node.setSubComponent("nic", "macro.SnapprNIC")

  nic.setSubComponent("outport", "macro.SnapprOutPort")

  #build the memory system
  node.setSubComponent("memory", "macro.snappr_memory")

sideX = 0.5
sideY = 0.5
sideZ = 0.5

for i in range(num_switches):
  connections = system.switchConnections(i)
  switch = switches[i]
  switch_geometry = system.switchGeometry(i)
  for src_id, dst_id, src_outport, dst_inport in connections:
      link_name = "network%d:%d->%d:%d" % (src_id,src_outport,dst_id,dst_inport)
      link = sst.Link(link_name)
      port_name = "output%d" % (src_outport)
      switch.addLink(link,port_name,link_latency)
      dst_switch = switches[dst_id]
      port_name = "input%d" % (dst_inport)
      dst_switch.addLink(link,port_name,link_latency)

first_ej_port = -1
print("Connecting endpoints")
for sw_id in range(num_switches):
  connections = system.ejectionConnections(sw_id)
  for ep_id, switch_port, ej_port in connections:
    if first_ej_port == -1:
      first_ej_port = switch_port
    first_ej_port = min(first_ej_port,switch_port)
    ep = nodes[ep_id]
    switch = switches[sw_id]

    link_name = "ejection%d:%d->%d:%d" % (ep_id,ej_port,sw_id,switch_port)
    link = sst.Link(link_name)

    port_name = "output%d" % (switch_port)
    switch.addLink(link,port_name,link_latency)

    port_name = "input%d" % (ej_port)
    ep.addLink(link,port_name,link_latency)
    switch.setSubComponent("outport%d" % switch_port, "macro.SnapprOutPort")

  connections = system.ejectionConnections(sw_id)
  for ep_id, switch_port, inj_port, in connections:
    ep = nodes[ep_id]
    switch = switches[sw_id]

    link_name = "injection%d:%d->%d:%d" % (ep_id,inj_port,sw_id,switch_port)
    link = sst.Link(link_name)

    port_name = "input%d" % (switch_port)
    switch.addLink(link,port_name,link_latency)

    port_name = "output%d" % (ej_port)
    ep.addLink(link,port_name,link_latency)
    
    ep.setSubComponent("outport%d" % ej_port, "macro.SnapprOutPort")

# have to do it this way because every slot gets a subcomponent,
# but not every port gets a link
for sw_id in range(num_switches):
  switch = switches[sw_id]
  p = 0;
  for j in range(0,first_ej_port):
      stat_params = dict(
        origin=[1, 1 + p, 1],
        size=[sideX, sideY, sideZ],
        shape="line",
        type="sst.IntensityStatistic",
      )
      p = p + 1
      port = switch.setSubComponent("outport%d" % j, "macro.SnapprOutPort")
      port.enableStatistics(["traffic_intensity"], stat_params)

nproc = sst.getMPIRankCount() * sst.getThreadCount()
logp_switches = [None]*nproc
for i in range(nproc):
  switch = sst.Component("LogP %d" % i, "macro.logp_switch")
  switch.addParams(dict(
    bandwidth=link_bandwidth,
    hop_latency="100ns",
    out_in_latency="2us"
  ))
  logp_switches[i] = switch

for i in range(num_nodes):
  ep = nodes[i]
  for p in range(nproc):
    print("Injection %d on switch %d" % (p,nproc))
    sw = logp_switches[p]
    inj_sw = system.nodeToLogPSwitch(i)
    #use inj_sw to set a no-cut

    link_name = "logPinjection%d->%d" % (i, p)
    link = sst.Link(link_name)
    port_name = "output%d" % (sst.macro.NICLogPInjectionPort)
    ep.addLink(link, port_name, small_latency) #put no latency here
    port_name = "input%d" % (i)
    sw.addLink(link, port_name, small_latency)

    link_name = "logPejection%d->%d" % (p, i)
    link = sst.Link(link_name)
    port_name = "input%d" % (sst.macro.NICLogPInjectionPort)
    ep.addLink(link, port_name, small_latency) #put no latency here
    port_name = "output%d" % (i)
    sw.addLink(link, port_name, small_latency)

sst.setStatisticLoadLevel(7)
sst.setStatisticOutput("sst.vtkstatisticoutputexodus")
sst.macro.debug("mpi")
