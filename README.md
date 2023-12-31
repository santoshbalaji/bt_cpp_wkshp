# bt_cpp_wkshp
This repository is for simulating actions of turtlebot with behavior trees

## Dependencies involved
- [ ] behaviortree_cpp
- [ ] behaviortree_ros2
- [ ] std_msgs
- [ ] action_tutorials_interfaces
- [ ] btcpp_ros2_interfaces

## Install dependencies
- To install dependencies for bt_cpp_wkshp package
```
  rosdep install --from-paths src/bt_cpp_wkshp -y --ignore-src
```

## Build and Execution
- To build the package
```
  colcon build --symlink-install
```

- To start external systems
```
  ros2 topic pub /prepare_item std_msgs/msg/String {}
```
```
  ros2 run btcpp_ros2_samples sleep_server
```

- To start simulation
```
  ros2 run bt_cpp_wkshp start_tree
```

## Download groot2
```
  https://www.behaviortree.dev/groot/
```

## How to visualize the nodes in groot2
- Groot monitor mode screen
![1](docs/1.png)

- Click on button right next to Executor server for starting monitor mode when behavior tree is running
![2](docs/2.png)

- Screen after behavior tree run is completed
![3](docs/3.png)
