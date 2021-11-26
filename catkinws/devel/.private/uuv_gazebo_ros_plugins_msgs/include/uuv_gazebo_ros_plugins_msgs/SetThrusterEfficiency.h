// Generated by gencpp from file uuv_gazebo_ros_plugins_msgs/SetThrusterEfficiency.msg
// DO NOT EDIT!


#ifndef UUV_GAZEBO_ROS_PLUGINS_MSGS_MESSAGE_SETTHRUSTEREFFICIENCY_H
#define UUV_GAZEBO_ROS_PLUGINS_MSGS_MESSAGE_SETTHRUSTEREFFICIENCY_H

#include <ros/service_traits.h>


#include <uuv_gazebo_ros_plugins_msgs/SetThrusterEfficiencyRequest.h>
#include <uuv_gazebo_ros_plugins_msgs/SetThrusterEfficiencyResponse.h>


namespace uuv_gazebo_ros_plugins_msgs
{

struct SetThrusterEfficiency
{

typedef SetThrusterEfficiencyRequest Request;
typedef SetThrusterEfficiencyResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetThrusterEfficiency
} // namespace uuv_gazebo_ros_plugins_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency > {
  static const char* value()
  {
    return "60f827235457ddfd6a19b596030b49ad";
  }

  static const char* value(const ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency&) { return value(); }
};

template<>
struct DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency > {
  static const char* value()
  {
    return "uuv_gazebo_ros_plugins_msgs/SetThrusterEfficiency";
  }

  static const char* value(const ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency&) { return value(); }
};


// service_traits::MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyRequest> should match
// service_traits::MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency >
template<>
struct MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyRequest>
{
  static const char* value()
  {
    return MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency >::value();
  }
  static const char* value(const ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyRequest> should match
// service_traits::DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency >
template<>
struct DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyRequest>
{
  static const char* value()
  {
    return DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency >::value();
  }
  static const char* value(const ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyResponse> should match
// service_traits::MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency >
template<>
struct MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyResponse>
{
  static const char* value()
  {
    return MD5Sum< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency >::value();
  }
  static const char* value(const ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyResponse> should match
// service_traits::DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency >
template<>
struct DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyResponse>
{
  static const char* value()
  {
    return DataType< ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiency >::value();
  }
  static const char* value(const ::uuv_gazebo_ros_plugins_msgs::SetThrusterEfficiencyResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // UUV_GAZEBO_ROS_PLUGINS_MSGS_MESSAGE_SETTHRUSTEREFFICIENCY_H
