#include "msg_0x0b_playerposition_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

PlayerPosition::PlayerPosition()
{
	_pf_packetId = static_cast<int8_t>(0x0B);
	_pf_initialized = false;
}

PlayerPosition::PlayerPosition(double _x, double _y, double _stance, double _z, bool _onGround)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_stance(_stance)
	,	_pf_z(_z)
	,	_pf_onGround(_onGround)
{
	_pf_packetId = static_cast<int8_t>(0x0B);
	_pf_initialized = true;
}


size_t PlayerPosition::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteDouble(_dst, _offset, _pf_x);
	_offset = WriteDouble(_dst, _offset, _pf_y);
	_offset = WriteDouble(_dst, _offset, _pf_stance);
	_offset = WriteDouble(_dst, _offset, _pf_z);
	_offset = WriteBool(_dst, _offset, _pf_onGround);


	return _offset;
}

size_t PlayerPosition::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadDouble(_src, _offset, _pf_x);
	_offset = ReadDouble(_src, _offset, _pf_y);
	_offset = ReadDouble(_src, _offset, _pf_stance);
	_offset = ReadDouble(_src, _offset, _pf_z);
	_offset = ReadBool(_src, _offset, _pf_onGround);
	_pf_initialized = true;
	return _offset;
}

double PlayerPosition::getX() const { return _pf_x; }
double PlayerPosition::getY() const { return _pf_y; }
double PlayerPosition::getStance() const { return _pf_stance; }
double PlayerPosition::getZ() const { return _pf_z; }
bool PlayerPosition::getOnGround() const { return _pf_onGround; }

void PlayerPosition::setX(double _val) { _pf_x = _val; }
void PlayerPosition::setY(double _val) { _pf_y = _val; }
void PlayerPosition::setStance(double _val) { _pf_stance = _val; }
void PlayerPosition::setZ(double _val) { _pf_z = _val; }
void PlayerPosition::setOnGround(bool _val) { _pf_onGround = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
