cmake_minimum_required(VERSION 3.8)
project(bt_cpp_wkshp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(behaviortree_ros2 REQUIRED)
find_package(std_msgs REQUIRED)
find_package(action_tutorials_interfaces REQUIRED)
find_package(btcpp_ros2_interfaces REQUIRED)

include_directories(include)

add_executable(
  start_tree
  src/main.cpp
  src/alarm.cpp
  src/check_item_status_at_robot.cpp
  src/move_robot_to_pose.cpp
  src/operate_asrs_conveyor.cpp
  src/operate_robot_conveyor.cpp
  src/prepare_item_at_asrs.cpp)

ament_target_dependencies(
  start_tree
  behaviortree_cpp
  behaviortree_ros2
  std_msgs
  action_tutorials_interfaces
  btcpp_ros2_interfaces
)

install(TARGETS
  start_tree
  DESTINATION lib/${PROJECT_NAME}
)
  
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
