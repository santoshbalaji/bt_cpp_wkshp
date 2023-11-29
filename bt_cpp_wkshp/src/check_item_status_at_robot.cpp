#include <bt_cpp_wkshp/check_item_status_at_robot.hpp>

namespace bt_cpp_wkshp
{
  CheckItemStatusAtRobot:: CheckItemStatusAtRobot(
    const std::string& name, const NodeConfig& config) : SyncActionNode(name, config)
  {}

  PortsList CheckItemStatusAtRobot::providedPorts()
  {
    return {
      BT::InputPort<std::string>("item_code")
    };
  }

  NodeStatus CheckItemStatusAtRobot::tick() 
  {  
    unsigned int seed = time(NULL);
    int choice = rand_r(&seed) % 2;
    std::string state = choice ==  0 ? "Success" : "Failure";
    std::cout << "The item transfer status on robot is: " << state;
    return choice ==  0 ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
  }
}