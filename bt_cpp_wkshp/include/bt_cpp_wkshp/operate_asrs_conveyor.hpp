#ifndef BT_CPP_WKSHP__OPERATE_ASRS_CONVEYOR_HPP_
#define BT_CPP_WKSHP__OPERATE_ASRS_CONVEYOR_HPP_

#include <behaviortree_ros2/bt_action_node.hpp>
#include <btcpp_ros2_interfaces/action/sleep.hpp>

namespace bt_cpp_wkshp
{

class OperateASRSConveyor: public BT::RosActionNode<
  btcpp_ros2_interfaces::action::Sleep>
{
public:
  OperateASRSConveyor(const std::string& name,
              const BT::NodeConfig& conf,
              const BT::RosNodeParams& params) : 
      RosActionNode<btcpp_ros2_interfaces::action::Sleep>(name, conf, params)
  {}

  static BT::PortsList providedPorts()
  {
    return providedBasicPorts({BT::InputPort<unsigned>("msec")});
  }

  bool setGoal(Goal& goal) override;
  void onHalt() override;
  BT::NodeStatus onResultReceived(const WrappedResult& wr) override;
  virtual BT::NodeStatus onFailure(BT::ActionNodeErrorCode error) override;
};
} // namespace bt_training

#endif  // BT_CPP_WKSHP__OPERATE_ASRS_CONVEYOR_HPP_
