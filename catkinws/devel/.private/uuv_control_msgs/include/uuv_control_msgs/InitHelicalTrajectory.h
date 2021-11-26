// Generated by gencpp from file uuv_control_msgs/InitHelicalTrajectory.msg
// DO NOT EDIT!


#ifndef UUV_CONTROL_MSGS_MESSAGE_INITHELICALTRAJECTORY_H
#define UUV_CONTROL_MSGS_MESSAGE_INITHELICALTRAJECTORY_H

#include <ros/service_traits.h>


#include <uuv_control_msgs/InitHelicalTrajectoryRequest.h>
#include <uuv_control_msgs/InitHelicalTrajectoryResponse.h>


namespace uuv_control_msgs
{

struct InitHelicalTrajectory
{

typedef InitHelicalTrajectoryRequest Request;
typedef InitHelicalTrajectoryResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct InitHelicalTrajectory
} // namespace uuv_control_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::uuv_control_msgs::InitHelicalTrajectory > {
  static const char* value()
  {
    return "bae09a54d9b06eeca193015644eeb493";
  }

  static const char* value(const ::uuv_control_msgs::InitHelicalTrajectory&) { return value(); }
};

template<>
struct DataType< ::uuv_control_msgs::InitHelicalTrajectory > {
  static const char* value()
  {
    return "uuv_control_msgs/InitHelicalTrajectory";
  }

  static const char* value(const ::uuv_control_msgs::InitHelicalTrajectory&) { return value(); }
};


// service_traits::MD5Sum< ::uuv_control_msgs::InitHelicalTrajectoryRequest> should match
// service_traits::MD5Sum< ::uuv_control_msgs::InitHelicalTrajectory >
template<>
struct MD5Sum< ::uuv_control_msgs::InitHelicalTrajectoryRequest>
{
  static const char* value()
  {
    return MD5Sum< ::uuv_control_msgs::InitHelicalTrajectory >::value();
  }
  static const char* value(const ::uuv_control_msgs::InitHelicalTrajectoryRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::uuv_control_msgs::InitHelicalTrajectoryRequest> should match
// service_traits::DataType< ::uuv_control_msgs::InitHelicalTrajectory >
template<>
struct DataType< ::uuv_control_msgs::InitHelicalTrajectoryRequest>
{
  static const char* value()
  {
    return DataType< ::uuv_control_msgs::InitHelicalTrajectory >::value();
  }
  static const char* value(const ::uuv_control_msgs::InitHelicalTrajectoryRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::uuv_control_msgs::InitHelicalTrajectoryResponse> should match
// service_traits::MD5Sum< ::uuv_control_msgs::InitHelicalTrajectory >
template<>
struct MD5Sum< ::uuv_control_msgs::InitHelicalTrajectoryResponse>
{
  static const char* value()
  {
    return MD5Sum< ::uuv_control_msgs::InitHelicalTrajectory >::value();
  }
  static const char* value(const ::uuv_control_msgs::InitHelicalTrajectoryResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::uuv_control_msgs::InitHelicalTrajectoryResponse> should match
// service_traits::DataType< ::uuv_control_msgs::InitHelicalTrajectory >
template<>
struct DataType< ::uuv_control_msgs::InitHelicalTrajectoryResponse>
{
  static const char* value()
  {
    return DataType< ::uuv_control_msgs::InitHelicalTrajectory >::value();
  }
  static const char* value(const ::uuv_control_msgs::InitHelicalTrajectoryResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // UUV_CONTROL_MSGS_MESSAGE_INITHELICALTRAJECTORY_H
