#ifndef BT_CPP_WKSHP__OPERATE_ROBOT_CONVEYOR_HPP_
#define BT_CPP_WKSHP__OPERATE_ROBOT_CONVEYOR_HPP_

#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_cpp/action_node.h>
#include <behaviortree_cpp/tree_node.h>
#include <behaviortree_cpp/basic_types.h>

using StatefulActionNode = BT::StatefulActionNode;
using NodeConfig = BT::NodeConfig;
using NodeStatus = BT::NodeStatus;
using PortsList = BT::PortsList;

namespace bt_cpp_wkshp
{

// To mimic operation of robot conveyor
// Asynchronous node which sends success after some period of time
class OperateRobotConveyor : public StatefulActionNode
{
  public:
    OperateRobotConveyor(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;
  
  private:
    std::chrono::system_clock::time_point _completion_time;
};

}  // namespace bt_training


#endif  // BT_CPP_WKSHP__OPERATE_ROBOT_CONVEYOR_HPP_
