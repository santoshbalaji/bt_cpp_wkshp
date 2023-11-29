#include <bt_cpp_wkshp/operate_asrs_conveyor.hpp>
#include <behaviortree_ros2/plugins.hpp>
#include <rclcpp/rclcpp.hpp>

namespace bt_cpp_wkshp
{
  bool OperateASRSConveyor::setGoal(RosActionNode::Goal &goal)
  {
    auto timeout = getInput<unsigned>("msec");
    goal.msec_timeout = timeout.value();
    return true;
  }

  BT::NodeStatus OperateASRSConveyor::onResultReceived(const RosActionNode::WrappedResult &wr)
  {
    return BT::NodeStatus::SUCCESS;
  }

  BT::NodeStatus OperateASRSConveyor::onFailure(BT::ActionNodeErrorCode error)
  {
    return BT::NodeStatus::FAILURE;
  }

  void OperateASRSConveyor::onHalt()
  {
  }
}
