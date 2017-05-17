cmake_minimum_required(VERSION 2.8.3)
project(robot1_description)

#required packages
find_package(catkin REQUIRED COMPONENTS
  robot_state_publisher
  roscpp
  rospy
  std_msgs
  tf
  urdf
  xacro
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES gpsTest
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(state_publisher_tutorials src/state_publisher.cpp)
add_dependencies(state_publisher_tutorials src/state_publisher.cpp)

target_link_libraries(state_publisher_tutorials
   ${catkin_LIBRARIES}
 )

