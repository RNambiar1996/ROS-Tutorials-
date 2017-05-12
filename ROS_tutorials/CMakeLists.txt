cmake_minimum_required(VERSION 2.8.3)
project(ROS_tutorials)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  #dynamixel_msgs
  geometry_msgs
  joy
  #nav_msgs
  roscpp
  rospy
  #sensor_msgs
  std_msgs
  #tf
  #pcl_conversions
  #pcl_ros
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(dynamixel src/dynamixel.cpp)
#add_executable(kinect src/kinect.cpp)
add_executable(gpsTest src/gpsTest.cpp)
add_executable(imu_test src/imu_test.cpp)
add_executable(imu_arduino src/imu_arduino.cpp)

target_link_libraries(dynamixel
   ${catkin_LIBRARIES} ${PCL_LIBRARIES}
)
target_link_libraries(gpsTest
   ${catkin_LIBRARIES} ${PCL_LIBRARIES}
)
#target_link_libraries(kinect
#  ${catkin_LIBRARIES} ${PCL_LIBRARIES}
#)
target_link_libraries(imu_test
   ${catkin_LIBRARIES} ${PCL_LIBRARIES}
)
target_link_libraries(imu_arduino
   ${catkin_LIBRARIES} ${PCL_LIBRARIES}
)

add_dependencies(dynamixel src/dynamixels.cpp)
add_dependencies(gpsTest src/gpsTest.cpp)
#add_dependencies(kinect src/dynamixel.cpp)
add_dependencies(imu_test src/imu_test.cpp)
add_dependencies(imu_arduino src/imu_arduino.cpp)


