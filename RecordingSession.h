#ifndef MULTI_INDEXED_SANDBOX_RECORDINGSESSION_H
#define MULTI_INDEXED_SANDBOX_RECORDINGSESSION_H

//@CODEGEN
#include <vector>
#include <string>
#include <ostream>

struct HostAndPort
{//@GEN_EQ_OUT
  std::string _host;
  int _port;
};

struct RecSessKey
{//@GEN_LESS_EQ_OUT
  std::string _clientName;
  int _recSessId;
  RecSessKey() : _recSessId(0) {}
  RecSessKey(const std::string & clientName, int recSessId) : _clientName(clientName), _recSessId(recSessId) {}
};

struct RecordingSession
{//@GEN_EQ_OUT
  std::string _callUID;
  std::string _httpStorageURL;
  HostAndPort _rtpDstA;
  HostAndPort _rtpDstB;
};

struct RecSessData
{//@GEN_LESS_EQ_OUT
  RecSessKey _recSessKey;
  RecordingSession _recSess;
  int _mrId;
  const std::string & getClientName() const
  {
    return _recSessKey._clientName;
  };
  struct clientName {};
  struct recSessKey {};
  struct mrId {};
};

#include "MapData_Gen.h"
#endif //MULTI_INDEXED_SANDBOX_RECORDINGSESSION_H
