cmake_minimum_required(VERSION 3.0.2)
project(mono_depth2)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  geometry_msgs
  visualization_msgs
  message_generation
  roscpp
  rospy
  std_msgs
  sensor_msgs
)
catkin_python_setup()


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



add_service_files(
  FILES
  MonoDepth.srv
)

#add_message_files(
#    FILES
#)

generate_messages(DEPENDENCIES actionlib_msgs geometry_msgs std_msgs sensor_msgs)

catkin_package(
#  INCLUDE_DIRS include
  #LIBRARIES flow_net
  CATKIN_DEPENDS rospy std_msgs message_runtime
#  DEPENDS system_lib
)



