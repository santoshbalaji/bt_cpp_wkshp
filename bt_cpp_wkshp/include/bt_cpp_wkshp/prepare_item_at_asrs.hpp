#ifndef BT_CPP_WKSHP__PREPARE_ITEM_AT_ASRS_HPP_
#define BT_CPP_WKSHP__PREPARE_ITEM_AT_ASRS_HPP_

#include <behaviortree_ros2/bt_topic_sub_node.hpp>
#include <std_msgs/msg/string.hpp>

namespace bt_cpp_wkshp
{

// To mimic item prepartion at asrs
// ROS action node which subscribes to external system
class PrepareItemAtASRS: public BT::RosTopicSubNode<std_msgs::msg::String>
{

public:
  PrepareItemAtASRS(const std::string& name,
                const BT::NodeConfig& conf,
                const BT::RosNodeParams& params);

  static BT::PortsList providedPorts();

  BT::NodeStatus onTick(
    const std::shared_ptr<std_msgs::msg::String>& last_msg) override;
};

}  // namespace bt_training

#endif  // BT_CPP_WKSHP__PREPARE_ITEM_AT_ASRS_HPP_
