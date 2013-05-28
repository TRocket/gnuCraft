#include "msg_0xd0_displayscoreboard_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

DisplayScoreboard::DisplayScoreboard()
{
	_pf_packetId = static_cast<int8_t>(0xD0);
	_pf_initialized = false;
}

DisplayScoreboard::DisplayScoreboard(int8_t _position, const String16& _scoreName)
	:	_pf_position(_position)
	,	_pf_scoreName(_scoreName)
{
	_pf_packetId = static_cast<int8_t>(0xD0);
	_pf_initialized = true;
}


size_t DisplayScoreboard::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_position);
	_offset = WriteString16(_dst, _offset, _pf_scoreName);


	return _offset;
}

size_t DisplayScoreboard::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_position);
	_offset = ReadString16(_src, _offset, _pf_scoreName);
	_pf_initialized = true;
	return _offset;
}

int8_t DisplayScoreboard::getPosition() const { return _pf_position; }
const String16& DisplayScoreboard::getScoreName() const { return _pf_scoreName; }

void DisplayScoreboard::setPosition(int8_t _val) { _pf_position = _val; }
void DisplayScoreboard::setScoreName(const String16& _val) { _pf_scoreName = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
