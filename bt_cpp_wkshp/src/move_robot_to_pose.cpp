#include <bt_cpp_wkshp/move_robot_to_pose.hpp>

#include <chrono>

namespace bt_cpp_wkshp
{

  MoveRobotToPose:: MoveRobotToPose(
    const std::string& name, const NodeConfig& config) : StatefulActionNode(name, config)
  {}

  PortsList MoveRobotToPose::providedPorts()
  {
    return {
      BT::InputPort<float>("x"),
      BT::InputPort<float>("y"),
    };
  }

  BT::NodeStatus MoveRobotToPose::onStart()
  {
    std::cout << "[ MoveRobotToPose: On start ]" << std::endl;
    _completion_time = std::chrono::system_clock::now() + std::chrono::milliseconds(2000);
    return BT::NodeStatus::RUNNING;
  }

  void MoveRobotToPose::onHalted()
  {
    std::cout << "[ MoveRobotToPose: Aborted ]" << std::endl;
  }

  BT::NodeStatus MoveRobotToPose::onRunning()
  {
    std::cout << "[ MoveRobotToPose: On Run ]" << std::endl;

    if(std::chrono::system_clock::now() >= _completion_time)
    {
      std::cout << "[ MoveRobotToPose: FINISHED ]" << std::endl;
      return BT::NodeStatus::SUCCESS;
    }

    return NodeStatus::RUNNING;
  }
}
