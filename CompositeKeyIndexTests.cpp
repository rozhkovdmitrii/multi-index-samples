#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/mem_fun.hpp>

#include "gtest/gtest.h"

struct HostAndPort
{
  std::string _host;
  int _port;
};



struct PlainRecSessData
{
  std::string _clientName;
  int _recSessId;
  int mrId;

  std::string _callUID;
  std::string _httpStorageURL;
  HostAndPort _rtpDstA;
  HostAndPort _rtpDstB;
};
