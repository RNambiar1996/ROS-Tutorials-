cmake_minimum_required(VERSION 2.8.3)
project(robot1_description)

## Add support for C++11, supported in ROS Kinetic and newer
# add_definitions(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  robot_state_publisher
  roscpp
  rospy
  std_msgs
  tf
  urdf
  xacro
)


add_executable(state_publisher_robot src/state_publisher.cpp)
add_dependencies(state_publisher_robot src/state_publisher.cpp)

target_link_libraries(state_publisher_robot
   ${catkin_LIBRARIES}
 )

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

