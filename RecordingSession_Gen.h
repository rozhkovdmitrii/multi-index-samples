//-----------------------------------------------------------------------------
//----THIS IS A GENERATED FILE, DO NOT TRY TO MODIFY IT
//----Authors: 2012-2014 Krasheninnikov Alexander, RD IUT
//----         2014      Kunavin Pavel, RD IUT
//----Contact kunavin@iskrauraltel.ru for details
//-----------------------------------------------------------------------------
#ifndef RecordingSession_GenH
#define RecordingSession_GenH
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
bool operator ==(const RecSessData & lhs, const RecSessData & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED != OPERATORS
//-----------------------------------------------------------------------------
bool operator !=(const HostAndPort & lhs, const HostAndPort & rhs);
bool operator !=(const RecSessKey & lhs, const RecSessKey & rhs);
bool operator !=(const RecordingSession & lhs, const RecordingSession & rhs);
bool operator !=(const RecSessData & lhs, const RecSessData & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED < OPERATORS
//-----------------------------------------------------------------------------
bool operator <(const RecSessKey & lhs, const RecSessKey & rhs);
bool operator <(const RecSessData & lhs, const RecSessData & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED >= OPERATORS
//-----------------------------------------------------------------------------
bool operator >=(const RecSessKey & lhs, const RecSessKey & rhs);
bool operator >=(const RecSessData & lhs, const RecSessData & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED <= OPERATORS
//-----------------------------------------------------------------------------
bool operator <=(const RecSessKey & lhs, const RecSessKey & rhs);
bool operator <=(const RecSessData & lhs, const RecSessData & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED > OPERATORS
//-----------------------------------------------------------------------------
bool operator >(const RecSessKey & lhs, const RecSessKey & rhs);
bool operator >(const RecSessData & lhs, const RecSessData & rhs);
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//---GENERATED << OPERATORS
//-----------------------------------------------------------------------------
std::ostream & operator <<(std::ostream & os, const HostAndPort & obj);
std::ostream & operator <<(std::ostream & os, const RecSessKey & obj);
std::ostream & operator <<(std::ostream & os, const RecordingSession & obj);
std::ostream & operator <<(std::ostream & os, const RecSessData & obj);
//-----------------------------------------------------------------------------
#endif//RecordingSession_GenH

