#include "msg_0x04_timeupdate_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

TimeUpdate::TimeUpdate()
{
	_pf_packetId = static_cast<int8_t>(0x04);
	_pf_initialized = false;
}

TimeUpdate::TimeUpdate(int64_t _worldAge, int64_t _timeOfDay)
	:	_pf_worldAge(_worldAge)
	,	_pf_timeOfDay(_timeOfDay)
{
	_pf_packetId = static_cast<int8_t>(0x04);
	_pf_initialized = true;
}


size_t TimeUpdate::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt64(_dst, _offset, _pf_worldAge);
	_offset = WriteInt64(_dst, _offset, _pf_timeOfDay);


	return _offset;
}

size_t TimeUpdate::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt64(_src, _offset, _pf_worldAge);
	_offset = ReadInt64(_src, _offset, _pf_timeOfDay);
	_pf_initialized = true;
	return _offset;
}

int64_t TimeUpdate::getWorldAge() const { return _pf_worldAge; }
int64_t TimeUpdate::getTimeOfDay() const { return _pf_timeOfDay; }

void TimeUpdate::setWorldAge(int64_t _val) { _pf_worldAge = _val; }
void TimeUpdate::setTimeOfDay(int64_t _val) { _pf_timeOfDay = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
