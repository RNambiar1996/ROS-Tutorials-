cmake_minimum_required(VERSION 2.8.3)
project(ROS_tutorials)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
#	dynamixel_msgs
  geometry_msgs
  joy
  #nav_msgs
  roscpp
  rospy
  #sensor_msgs
  std_msgs
 # tf
 # pcl_conversions
 # pcl_ros
)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ROS_tutorials
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(ROS_tutorials
#   src/${PROJECT_NAME}/ROS_tutorials.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(ROS_tutorials ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

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

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
install(TARGETS c4_example1 c4_example1
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_ROS_tutorials.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

