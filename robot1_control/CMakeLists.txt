cmake_minimum_required(VERSION 2.8.3)
project(robot1_control)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
	sensor_msgs
	geometry_msgs
)

## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES robot1_control
#  CATKIN_DEPENDS roscpp rospy std_msgs tf
#  DEPENDS system_lib
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)


## Declare a C++ executable
# add_executable(robot1_control_node src/robot1_control_node.cpp)
add_executable(teleopJoy src/robot1_joystick.cpp)
## Add cmake target dependencies of the executable
## same as for the library above
#add_dependencies(robot1_control_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(teleopJoy src/robot1_joystick.cpp)
## Specify libraries to link a library or executable target against
target_link_libraries(teleopJoy
   ${catkin_LIBRARIES}
)

