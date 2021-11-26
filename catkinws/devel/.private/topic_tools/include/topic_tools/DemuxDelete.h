// Generated by gencpp from file topic_tools/DemuxDelete.msg
// DO NOT EDIT!


#ifndef TOPIC_TOOLS_MESSAGE_DEMUXDELETE_H
#define TOPIC_TOOLS_MESSAGE_DEMUXDELETE_H

#include <ros/service_traits.h>


#include <topic_tools/DemuxDeleteRequest.h>
#include <topic_tools/DemuxDeleteResponse.h>


namespace topic_tools
{

struct DemuxDelete
{

typedef DemuxDeleteRequest Request;
typedef DemuxDeleteResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct DemuxDelete
} // namespace topic_tools


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::topic_tools::DemuxDelete > {
  static const char* value()
  {
    return "d8f94bae31b356b24d0427f80426d0c3";
  }

  static const char* value(const ::topic_tools::DemuxDelete&) { return value(); }
};

template<>
struct DataType< ::topic_tools::DemuxDelete > {
  static const char* value()
  {
    return "topic_tools/DemuxDelete";
  }

  static const char* value(const ::topic_tools::DemuxDelete&) { return value(); }
};


// service_traits::MD5Sum< ::topic_tools::DemuxDeleteRequest> should match
// service_traits::MD5Sum< ::topic_tools::DemuxDelete >
template<>
struct MD5Sum< ::topic_tools::DemuxDeleteRequest>
{
  static const char* value()
  {
    return MD5Sum< ::topic_tools::DemuxDelete >::value();
  }
  static const char* value(const ::topic_tools::DemuxDeleteRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::topic_tools::DemuxDeleteRequest> should match
// service_traits::DataType< ::topic_tools::DemuxDelete >
template<>
struct DataType< ::topic_tools::DemuxDeleteRequest>
{
  static const char* value()
  {
    return DataType< ::topic_tools::DemuxDelete >::value();
  }
  static const char* value(const ::topic_tools::DemuxDeleteRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::topic_tools::DemuxDeleteResponse> should match
// service_traits::MD5Sum< ::topic_tools::DemuxDelete >
template<>
struct MD5Sum< ::topic_tools::DemuxDeleteResponse>
{
  static const char* value()
  {
    return MD5Sum< ::topic_tools::DemuxDelete >::value();
  }
  static const char* value(const ::topic_tools::DemuxDeleteResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::topic_tools::DemuxDeleteResponse> should match
// service_traits::DataType< ::topic_tools::DemuxDelete >
template<>
struct DataType< ::topic_tools::DemuxDeleteResponse>
{
  static const char* value()
  {
    return DataType< ::topic_tools::DemuxDelete >::value();
  }
  static const char* value(const ::topic_tools::DemuxDeleteResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TOPIC_TOOLS_MESSAGE_DEMUXDELETE_H
