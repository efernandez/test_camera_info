cmake_minimum_required(VERSION 2.8.3)
project(test_camera_info)

find_package(catkin REQUIRED COMPONENTS
    camera_info_manager
    roscpp
    sensor_msgs)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS})

add_executable(test_camera_info src/test_camera_info.cpp)
target_link_libraries(test_camera_info ${catkin_LIBRARIES})

