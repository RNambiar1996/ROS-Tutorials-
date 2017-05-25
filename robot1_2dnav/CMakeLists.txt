cmake_minimum_required(VERSION 2.8.3)
project(robot1_2dnav)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	tf
	nav_msgs
	std_msgs
	geometry_msgs
	gazebo_ros
	genmsg
	actionlib_msgs
	actionlib
)

include_directories(
	${catkin_INCLUDE_DIRS}
)

catkin_package(
	DEPENDS
	gazebo_ros
	CATKIN_DEPENDS
	INCLUDE_DIRS
	LIBRARIES
)
