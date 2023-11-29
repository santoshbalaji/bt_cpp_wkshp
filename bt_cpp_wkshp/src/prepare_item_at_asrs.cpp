#include <bt_cpp_wkshp/prepare_item_at_asrs.hpp>

namespace bt_cpp_wkshp
{

  PrepareItemAtASRS::PrepareItemAtASRS(const std::string& name,
                const BT::NodeConfig& conf,
                const BT::RosNodeParams& params)
    : RosTopicSubNode<std_msgs::msg::String>(name, conf, params)
  {}

  BT::PortsList PrepareItemAtASRS::providedPorts()
  {
    BT::PortsList basic = {
      BT::InputPort<std::string>("item_code")
    };

    BT::PortsList pl = RosTopicSubNode<std_msgs::msg::String>::providedPorts();
    basic.insert(pl.begin(), pl.end());
    return basic;
  }

  BT::NodeStatus PrepareItemAtASRS::onTick(
    const std::shared_ptr<std_msgs::msg::String>& last_msg)
  {
    if(last_msg)
    {
      return BT::NodeStatus::SUCCESS;
    }
    else
    {
      return BT::NodeStatus::FAILURE; 
    }
  }
}
