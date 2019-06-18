#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/composite_key.hpp>

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
  struct recSessKey {};
};

using namespace boost::multi_index;

// Определение типа контейнера, пожалуй, самая запутанная часть работы с multi_index
typedef multi_index_container<
  PlainRecSessData, // 1. Тип хранимаого объекта
  indexed_by        // 2. Блок определения индексов ordered, hashed, ranked, random-access
  <
    ordered_unique
    <
      // tag - может отсутствовать, тогда обращение к индексу будет производиться по его номеру. В роли tag  используется класс-пустышка
      // member - ссылка на член класса RecSessData типа RecSessKey
      tag<PlainRecSessData::recSessKey>,
      composite_key
      <
        PlainRecSessData,
        member<PlainRecSessData, std::string, &PlainRecSessData::_clientName>,
        member<PlainRecSessData, int, &PlainRecSessData::_recSessId>
      >
    >
  >
> RecSessRelations;


