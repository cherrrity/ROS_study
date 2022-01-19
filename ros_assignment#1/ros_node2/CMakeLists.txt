cmake_minimum_required(VERSION 3.0.2)
project(ros_node2)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
  message
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
 INCLUDE_DIRS include
  LIBRARIES ros_node2
  CATKIN_DEPENDS roscpp std_msgs message
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# for publisher
add_executable(ros_node2 src/ros_node2.cpp)
add_dependencies(ros_node2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_node2 ${catkin_LIBRARIES})


