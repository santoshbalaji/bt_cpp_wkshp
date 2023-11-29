#ifndef BT_CPP_WKSHP__ALARM_HPP_
#define BT_CPP_WKSHP__ALARM_HPP_

#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_cpp/action_node.h>
#include <behaviortree_cpp/tree_node.h>
#include <behaviortree_cpp/basic_types.h>

using SyncActionNode = BT::SyncActionNode;
using NodeConfig = BT::NodeConfig;
using NodeStatus = BT::NodeStatus;
using PortsList = BT::PortsList;

namespace bt_cpp_wkshp
{

// To mimic notification behavior when system is failed
// Simple action node which always returns success
class Alarm : public SyncActionNode
{
  public:
    Alarm(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    NodeStatus tick();
};

}  // namespace bt_training


#endif  // BT_CPP_WKSHP__CHECK_ITEM_STATUS_AT_ROBOT_HPP_
