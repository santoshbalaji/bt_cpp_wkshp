#include <behaviortree_cpp/bt_factory.h>
#include <behaviortree_cpp/loggers/groot2_publisher.h>
#include <behaviortree_cpp/loggers/bt_file_logger_v2.h>
#include <behaviortree_cpp/loggers/bt_sqlite_logger.h>
#include <behaviortree_cpp/loggers/bt_cout_logger.h>

#include <behaviortree_ros2/bt_topic_sub_node.hpp>

#include <rclcpp/rclcpp.hpp>

#include <bt_cpp_wkshp/alarm.hpp>
#include <bt_cpp_wkshp/check_item_status_at_robot.hpp>
#include <bt_cpp_wkshp/move_robot_to_pose.hpp>
#include <bt_cpp_wkshp/operate_asrs_conveyor.hpp>
#include <bt_cpp_wkshp/operate_robot_conveyor.hpp>
#include <bt_cpp_wkshp/prepare_item_at_asrs.hpp>

using Alarm = bt_cpp_wkshp::Alarm;
using CheckItemStatusAtRobot = bt_cpp_wkshp::CheckItemStatusAtRobot;
using MoveRobotToPose = bt_cpp_wkshp::MoveRobotToPose;
using OperateASRSConveyor = bt_cpp_wkshp::OperateASRSConveyor;
using OperateRobotConveyor = bt_cpp_wkshp::OperateRobotConveyor;
using PrepareItemAtASRS = bt_cpp_wkshp::PrepareItemAtASRS;

static const char* xml_text = R"(
  <root BTCPP_format="4">
    <BehaviorTree>
      <Sequence>
        <Sequence>
          <MoveRobotToPose x="1.212" y="1.414" />
          <PrepareItemAtASRS topic_name="prepare_item" item_code="1213"/>
        </Sequence>
        <Sequence>
          <OperateASRSConveyor action_name="/sleep_service" msec="2000" state="stop" />
          <OperateRobotConveyor state="start" />
        </Sequence>
        <Fallback>
          <CheckItemStatusAtRobot item_code="1213" />
          <Alarm />
        </Fallback>
        <Sequence>
          <OperateASRSConveyor action_name="/sleep_service" msec="2000" state="stop" />
          <OperateRobotConveyor state="stop" />
        </Sequence>
      </Sequence>
    </BehaviorTree>
  </root>
 )";

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto nh = std::make_shared<rclcpp::Node>("bt_cpp_wkshp_node");

  BT::RosNodeParams params;
  params.nh = nh;

  BT::BehaviorTreeFactory factory;
  factory.registerNodeType<Alarm>("Alarm");
  factory.registerNodeType<CheckItemStatusAtRobot>("CheckItemStatusAtRobot");
  factory.registerNodeType<MoveRobotToPose>("MoveRobotToPose");
  factory.registerNodeType<OperateASRSConveyor>("OperateASRSConveyor", params);
  factory.registerNodeType<OperateRobotConveyor>("OperateRobotConveyor");
  factory.registerNodeType<PrepareItemAtASRS>("PrepareItemAtASRS", params);

  auto tree = factory.createTreeFromText(xml_text);

  BT::StdCoutLogger cout_logger(tree);
  BT::Groot2Publisher publisher(tree);
  BT::FileLogger2 file_logger(tree, "./generated_log.btlog");
  BT::SqliteLogger sqlite_logger(tree, "./generated_log.db3");
  BT::printTreeRecursively(tree.rootNode());

  tree.tickWhileRunning();

  return 0;
}
