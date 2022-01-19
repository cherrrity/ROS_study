cmake_minimum_required(VERSION 3.0.2)
project(message)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Message0.msg
  Message1.msg
  Message2.msg
  Message3.msg
)


## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)


catkin_package(
#  INCLUDE_DIRS include
# LIBRARIES message
 CATKIN_DEPENDS message_generation std_msgs roscpp rospy message_runtime
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)




