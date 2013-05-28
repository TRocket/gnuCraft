#include "msg_0x0e_playerdigging_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

PlayerDigging::PlayerDigging()
{
	_pf_packetId = static_cast<int8_t>(0x0E);
	_pf_initialized = false;
}

PlayerDigging::PlayerDigging(int8_t _status, int32_t _x, int8_t _y, int32_t _z, int8_t _face)
	:	_pf_status(_status)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_face(_face)
{
	_pf_packetId = static_cast<int8_t>(0x0E);
	_pf_initialized = true;
}


size_t PlayerDigging::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_status);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt8(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt8(_dst, _offset, _pf_face);


	return _offset;
}

size_t PlayerDigging::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_status);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt8(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_face);
	_pf_initialized = true;
	return _offset;
}

int8_t PlayerDigging::getStatus() const { return _pf_status; }
int32_t PlayerDigging::getX() const { return _pf_x; }
int8_t PlayerDigging::getY() const { return _pf_y; }
int32_t PlayerDigging::getZ() const { return _pf_z; }
int8_t PlayerDigging::getFace() const { return _pf_face; }

void PlayerDigging::setStatus(int8_t _val) { _pf_status = _val; }
void PlayerDigging::setX(int32_t _val) { _pf_x = _val; }
void PlayerDigging::setY(int8_t _val) { _pf_y = _val; }
void PlayerDigging::setZ(int32_t _val) { _pf_z = _val; }
void PlayerDigging::setFace(int8_t _val) { _pf_face = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
