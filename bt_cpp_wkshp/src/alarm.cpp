#include <bt_cpp_wkshp/alarm.hpp>

namespace bt_cpp_wkshp
{
  Alarm:: Alarm(
    const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
  {}

  PortsList Alarm::providedPorts()
  {
    return {};
  }

  NodeStatus Alarm::tick() 
  {
    return NodeStatus::SUCCESS;
  }
}
