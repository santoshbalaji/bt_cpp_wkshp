#include <bt_cpp_wkshp/operate_robot_conveyor.hpp>

#include <chrono>

namespace bt_cpp_wkshp
{

  OperateRobotConveyor:: OperateRobotConveyor(
    const std::string& name, const NodeConfig& config) : StatefulActionNode(name, config)
  {}

  PortsList OperateRobotConveyor::providedPorts()
  {
    return {
      BT::InputPort<std::string>("state")
    };
  }

  BT::NodeStatus OperateRobotConveyor::onStart()
  {
    std::cout << "[ OperateRobotConveyor: On start ]" << std::endl;
    _completion_time = std::chrono::system_clock::now() + std::chrono::milliseconds(2000);
    return BT::NodeStatus::RUNNING;
  }

  void OperateRobotConveyor::onHalted()
  {
    std::cout << "[ OperateRobotConveyor: Aborted ]" << std::endl;
  }

  BT::NodeStatus OperateRobotConveyor::onRunning()
  {
    std::cout << "[ OperateRobotConveyor: On Run ]" << std::endl;

    if(std::chrono::system_clock::now() >= _completion_time)
    {
      std::cout << "[ OperateRobotConveyor: FINISHED ]" << std::endl;
      return BT::NodeStatus::SUCCESS;
    }

    return NodeStatus::RUNNING;
  }
}
