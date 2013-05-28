#include "msg_0x0c_playerlook_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

PlayerLook::PlayerLook()
{
	_pf_packetId = static_cast<int8_t>(0x0C);
	_pf_initialized = false;
}

PlayerLook::PlayerLook(float _yaw, float _pitch, bool _onGround)
	:	_pf_yaw(_yaw)
	,	_pf_pitch(_pitch)
	,	_pf_onGround(_onGround)
{
	_pf_packetId = static_cast<int8_t>(0x0C);
	_pf_initialized = true;
}


size_t PlayerLook::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteFloat(_dst, _offset, _pf_yaw);
	_offset = WriteFloat(_dst, _offset, _pf_pitch);
	_offset = WriteBool(_dst, _offset, _pf_onGround);


	return _offset;
}

size_t PlayerLook::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadFloat(_src, _offset, _pf_yaw);
	_offset = ReadFloat(_src, _offset, _pf_pitch);
	_offset = ReadBool(_src, _offset, _pf_onGround);
	_pf_initialized = true;
	return _offset;
}

float PlayerLook::getYaw() const { return _pf_yaw; }
float PlayerLook::getPitch() const { return _pf_pitch; }
bool PlayerLook::getOnGround() const { return _pf_onGround; }

void PlayerLook::setYaw(float _val) { _pf_yaw = _val; }
void PlayerLook::setPitch(float _val) { _pf_pitch = _val; }
void PlayerLook::setOnGround(bool _val) { _pf_onGround = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
