cmake_minimum_required(VERSION 2.8.3)
project(robot1_control)


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

add_executable(teleopJoy src/robot1_joystick.cpp)
add_dependencies(teleopJoy src/robot1_joystick.cpp)
target_link_libraries(teleopJoy
	${catkin_LIBRARIES}
)

