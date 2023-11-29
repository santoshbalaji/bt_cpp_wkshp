#ifndef BT_CPP_WKSHP__MOVE_ROBOT_TO_POSE_HPP_
#define BT_CPP_WKSHP__MOVE_ROBOT_TO_POSE_HPP_

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

// To mimic movement of robot to a given pose
// Asynchronous node which sends success after some period of time
class MoveRobotToPose : public StatefulActionNode
{
  public:
    MoveRobotToPose(const std::string& name, const NodeConfig& config);
    static PortsList providedPorts();
    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;
  
  private:
    std::chrono::system_clock::time_point _completion_time;
};

}  // namespace bt_training


#endif  // BT_CPP_WKSHP__MOVE_ROBOT_TO_POSE_HPP_
