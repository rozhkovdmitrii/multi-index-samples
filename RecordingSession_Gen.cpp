//-----------------------------------------------------------------------------
//----THIS IS A GENERATED FILE, DO NOT TRY TO MODIFY IT
//----Authors: 2012-2014 Krasheninnikov Alexander, RD IUT
//----         2014      Kunavin Pavel, RD IUT
//----Contact kunavin@iskrauraltel.ru for details
//-----------------------------------------------------------------------------
#include "precomp.h"
#include "RecordingSession.h"
//-----------------------------------------------------------------------------
#ifndef LI_ASSERT
#define LI_ASSERT assert
#endif
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED == OPERATORS
//-----------------------------------------------------------------------------
bool operator ==(const HostAndPort & lhs, const HostAndPort & rhs)
{
  if (!(lhs._host == rhs._host)) return false;
  if (!(lhs._port == rhs._port)) return false;
  return true;
}
//-----------------------------------------------------------------------------
bool operator ==(const RecSessKey & lhs, const RecSessKey & rhs)
{
  if (!(lhs._clientName == rhs._clientName)) return false;
  if (!(lhs._recSessId == rhs._recSessId)) return false;
  return true;
}
//-----------------------------------------------------------------------------
bool operator ==(const RecordingSession & lhs, const RecordingSession & rhs)
{
  if (!(lhs._callUID == rhs._callUID)) return false;
  if (!(lhs._httpStorageURL == rhs._httpStorageURL)) return false;
  if (!(lhs._rtpDstA == rhs._rtpDstA)) return false;
  if (!(lhs._rtpDstB == rhs._rtpDstB)) return false;
  return true;
}
//-----------------------------------------------------------------------------
bool operator ==(const RecSessData & lhs, const RecSessData & rhs)
{
  if (!(lhs._recSessKey == rhs._recSessKey)) return false;
  if (!(lhs._recSess == rhs._recSess)) return false;
  if (!(lhs._mrId == rhs._mrId)) return false;
  return true;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED != OPERATORS
//-----------------------------------------------------------------------------
bool operator !=(const HostAndPort & lhs, const HostAndPort & rhs)
{
  return !(lhs == rhs);
}
//-----------------------------------------------------------------------------
bool operator !=(const RecSessKey & lhs, const RecSessKey & rhs)
{
  return !(lhs == rhs);
}
//-----------------------------------------------------------------------------
bool operator !=(const RecordingSession & lhs, const RecordingSession & rhs)
{
  return !(lhs == rhs);
}
//-----------------------------------------------------------------------------
bool operator !=(const RecSessData & lhs, const RecSessData & rhs)
{
  return !(lhs == rhs);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED < OPERATORS
//-----------------------------------------------------------------------------
bool operator <(const RecSessKey & lhs, const RecSessKey & rhs)
{
  if (!(lhs._clientName == rhs._clientName)) return lhs._clientName < rhs._clientName;
  if (!(lhs._recSessId == rhs._recSessId)) return lhs._recSessId < rhs._recSessId;
  return false;
}
//-----------------------------------------------------------------------------
bool operator <(const RecSessData & lhs, const RecSessData & rhs)
{
  if (!(lhs._recSessKey == rhs._recSessKey)) return lhs._recSessKey < rhs._recSessKey;
  if (!(lhs._recSess == rhs._recSess)) return lhs._recSess < rhs._recSess;
  if (!(lhs._mrId == rhs._mrId)) return lhs._mrId < rhs._mrId;
  return false;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED >= OPERATORS
//-----------------------------------------------------------------------------
bool operator >=(const RecSessKey & lhs, const RecSessKey & rhs)
{
  return !(lhs < rhs);
}
//-----------------------------------------------------------------------------
bool operator >=(const RecSessData & lhs, const RecSessData & rhs)
{
  return !(lhs < rhs);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED <= OPERATORS
//-----------------------------------------------------------------------------
bool operator <=(const RecSessKey & lhs, const RecSessKey & rhs)
{
  return (lhs < rhs) || (lhs == rhs);
}
//-----------------------------------------------------------------------------
bool operator <=(const RecSessData & lhs, const RecSessData & rhs)
{
  return (lhs < rhs) || (lhs == rhs);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED > OPERATORS
//-----------------------------------------------------------------------------
bool operator >(const RecSessKey & lhs, const RecSessKey & rhs)
{
  return !(lhs <= rhs);
}
//-----------------------------------------------------------------------------
bool operator >(const RecSessData & lhs, const RecSessData & rhs)
{
  return !(lhs <= rhs);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED << OPERATORS
//-----------------------------------------------------------------------------
std::ostream & operator <<(std::ostream & os, const HostAndPort & obj)
{
  os << "Host: " << obj._host;
  os << ", Port: " << obj._port;
  return os;
}
//-----------------------------------------------------------------------------
std::ostream & operator <<(std::ostream & os, const RecSessKey & obj)
{
  os << "ClientName: " << obj._clientName;
  os << ", RecSessId: " << obj._recSessId;
  return os;
}
//-----------------------------------------------------------------------------
std::ostream & operator <<(std::ostream & os, const RecordingSession & obj)
{
  os << "CallUID: " << obj._callUID;
  os << ", HttpStorageURL: " << obj._httpStorageURL;
  os << ", RtpDstA: " << obj._rtpDstA;
  os << ", RtpDstB: " << obj._rtpDstB;
  return os;
}
//-----------------------------------------------------------------------------
std::ostream & operator <<(std::ostream & os, const RecSessData & obj)
{
  os << "RecSessKey: " << obj._recSessKey;
  os << ", RecSess: " << obj._recSess;
  os << ", MrId: " << obj._mrId;
  return os;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

