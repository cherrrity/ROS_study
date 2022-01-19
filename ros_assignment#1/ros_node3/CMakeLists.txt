cmake_minimum_required(VERSION 3.0.2)
project(ros_node3)

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
add_executable(ros_node3 src/ros_node3.cpp)
add_dependencies(ros_node3 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_node3 ${catkin_LIBRARIES})

# for publisher
add_executable(ros_node4 src/ros_node4.cpp)
add_dependencies(ros_node4 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_node4 ${catkin_LIBRARIES})

# for publisher
add_executable(ros_node5 src/ros_node5.cpp)
add_dependencies(ros_node5 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_node5 ${catkin_LIBRARIES})


