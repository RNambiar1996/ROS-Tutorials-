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
	nav_msgs
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

add_executable(robot_tf_publisher src/tf_broadcaster.cpp)
add_dependencies(robot_tf_publisher src/tf_broadcaster.cpp)
target_link_libraries(robot_tf_publisher
	${catkin_LIBRARIES}
)

add_executable(tf_listener src/tf_listener.cpp)
add_dependencies(tf_listener src/tf_listener.cpp)
target_link_libraries(tf_listener
	${catkin_LIBRARIES}
)

add_executable(odometry src/odometry.cpp)
add_dependencies(odometry src/odometry.cpp)
target_link_libraries(odometry
	${catkin_LIBRARIES}
)
