#include "msg_0x12_animation_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Animation::Animation()
{
	_pf_packetId = static_cast<int8_t>(0x12);
	_pf_initialized = false;
}

Animation::Animation(int32_t _playerId, int8_t _animId)
	:	_pf_playerId(_playerId)
	,	_pf_animId(_animId)
{
	_pf_packetId = static_cast<int8_t>(0x12);
	_pf_initialized = true;
}


size_t Animation::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_playerId);
	_offset = WriteInt8(_dst, _offset, _pf_animId);


	return _offset;
}

size_t Animation::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_playerId);
	_offset = ReadInt8(_src, _offset, _pf_animId);
	_pf_initialized = true;
	return _offset;
}

int32_t Animation::getPlayerId() const { return _pf_playerId; }
int8_t Animation::getAnimId() const { return _pf_animId; }

void Animation::setPlayerId(int32_t _val) { _pf_playerId = _val; }
void Animation::setAnimId(int8_t _val) { _pf_animId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
