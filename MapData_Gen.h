//-----------------------------------------------------------------------------
//----THIS IS A GENERATED FILE, DO NOT TRY TO MODIFY IT
//----Authors: 2012-2014 Krasheninnikov Alexander, RD IUT
//----         2014      Kunavin Pavel, RD IUT
//----Contact kunavin@iskrauraltel.ru for details
//-----------------------------------------------------------------------------
#ifndef MapData_GenH
#define MapData_GenH
//-----------------------------------------------------------------------------
#ifndef LI_NOEXCEPT
#define LI_NOEXCEPT
#endif
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED == OPERATORS
//-----------------------------------------------------------------------------
bool operator ==(const HostAndPort & lhs, const HostAndPort & rhs);
bool operator ==(const RecSessKey & lhs, const RecSessKey & rhs);
bool operator ==(const RecordingSession & lhs, const RecordingSession & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED != OPERATORS
//-----------------------------------------------------------------------------
bool operator !=(const HostAndPort & lhs, const HostAndPort & rhs);
bool operator !=(const RecSessKey & lhs, const RecSessKey & rhs);
bool operator !=(const RecordingSession & lhs, const RecordingSession & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED < OPERATORS
//-----------------------------------------------------------------------------
bool operator <(const HostAndPort & lhs, const HostAndPort & rhs);
bool operator <(const RecSessKey & lhs, const RecSessKey & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED >= OPERATORS
//-----------------------------------------------------------------------------
bool operator >=(const HostAndPort & lhs, const HostAndPort & rhs);
bool operator >=(const RecSessKey & lhs, const RecSessKey & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED <= OPERATORS
//-----------------------------------------------------------------------------
bool operator <=(const HostAndPort & lhs, const HostAndPort & rhs);
bool operator <=(const RecSessKey & lhs, const RecSessKey & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED > OPERATORS
//-----------------------------------------------------------------------------
bool operator >(const HostAndPort & lhs, const HostAndPort & rhs);
bool operator >(const RecSessKey & lhs, const RecSessKey & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED << OPERATORS
//-----------------------------------------------------------------------------
std::ostream & operator <<(std::ostream & os, const HostAndPort & obj);
std::ostream & operator <<(std::ostream & os, const RecSessKey & obj);
std::ostream & operator <<(std::ostream & os, const RecordingSession & obj);
//-----------------------------------------------------------------------------
#endif//MapData_GenH

