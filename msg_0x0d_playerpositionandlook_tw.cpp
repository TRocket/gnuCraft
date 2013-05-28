#include "msg_0x0d_playerpositionandlook_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

PlayerPositionAndLook::PlayerPositionAndLook()
{
	_pf_packetId = static_cast<int8_t>(0x0D);
	_pf_initialized = false;
}

PlayerPositionAndLook::PlayerPositionAndLook(double _x, double _y, double _stance, double _z, float _yaw, float _pitch, bool _onGround)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_stance(_stance)
	,	_pf_z(_z)
	,	_pf_yaw(_yaw)
	,	_pf_pitch(_pitch)
	,	_pf_onGround(_onGround)
{
	_pf_packetId = static_cast<int8_t>(0x0D);
	_pf_initialized = true;
}


size_t PlayerPositionAndLook::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteDouble(_dst, _offset, _pf_x);
	_offset = WriteDouble(_dst, _offset, _pf_y);
	_offset = WriteDouble(_dst, _offset, _pf_stance);
	_offset = WriteDouble(_dst, _offset, _pf_z);
	_offset = WriteFloat(_dst, _offset, _pf_yaw);
	_offset = WriteFloat(_dst, _offset, _pf_pitch);
	_offset = WriteBool(_dst, _offset, _pf_onGround);


	return _offset;
}

size_t PlayerPositionAndLook::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadDouble(_src, _offset, _pf_x);
	_offset = ReadDouble(_src, _offset, _pf_stance);
	_offset = ReadDouble(_src, _offset, _pf_y);
	_offset = ReadDouble(_src, _offset, _pf_z);
	_offset = ReadFloat(_src, _offset, _pf_yaw);
	_offset = ReadFloat(_src, _offset, _pf_pitch);
	_offset = ReadBool(_src, _offset, _pf_onGround);
	_pf_initialized = true;
	return _offset;
}

double PlayerPositionAndLook::getX() const { return _pf_x; }
double PlayerPositionAndLook::getY() const { return _pf_y; }
double PlayerPositionAndLook::getStance() const { return _pf_stance; }
double PlayerPositionAndLook::getZ() const { return _pf_z; }
float PlayerPositionAndLook::getYaw() const { return _pf_yaw; }
float PlayerPositionAndLook::getPitch() const { return _pf_pitch; }
bool PlayerPositionAndLook::getOnGround() const { return _pf_onGround; }

void PlayerPositionAndLook::setX(double _val) { _pf_x = _val; }
void PlayerPositionAndLook::setY(double _val) { _pf_y = _val; }
void PlayerPositionAndLook::setStance(double _val) { _pf_stance = _val; }
void PlayerPositionAndLook::setZ(double _val) { _pf_z = _val; }
void PlayerPositionAndLook::setYaw(float _val) { _pf_yaw = _val; }
void PlayerPositionAndLook::setPitch(float _val) { _pf_pitch = _val; }
void PlayerPositionAndLook::setOnGround(bool _val) { _pf_onGround = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
