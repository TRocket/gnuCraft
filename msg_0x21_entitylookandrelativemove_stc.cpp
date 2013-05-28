#include "msg_0x21_entitylookandrelativemove_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityLookAndRelativeMove::EntityLookAndRelativeMove()
{
	_pf_packetId = static_cast<int8_t>(0x21);
	_pf_initialized = false;
}

EntityLookAndRelativeMove::EntityLookAndRelativeMove(int32_t _entityId, int8_t _dx, int8_t _dy, int8_t _dz, int8_t _yaw, int8_t _pitch)
	:	_pf_entityId(_entityId)
	,	_pf_dx(_dx)
	,	_pf_dy(_dy)
	,	_pf_dz(_dz)
	,	_pf_yaw(_yaw)
	,	_pf_pitch(_pitch)
{
	_pf_packetId = static_cast<int8_t>(0x21);
	_pf_initialized = true;
}


size_t EntityLookAndRelativeMove::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_dx);
	_offset = WriteInt8(_dst, _offset, _pf_dy);
	_offset = WriteInt8(_dst, _offset, _pf_dz);
	_offset = WriteInt8(_dst, _offset, _pf_yaw);
	_offset = WriteInt8(_dst, _offset, _pf_pitch);


	return _offset;
}

size_t EntityLookAndRelativeMove::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_dx);
	_offset = ReadInt8(_src, _offset, _pf_dy);
	_offset = ReadInt8(_src, _offset, _pf_dz);
	_offset = ReadInt8(_src, _offset, _pf_yaw);
	_offset = ReadInt8(_src, _offset, _pf_pitch);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityLookAndRelativeMove::getEntityId() const { return _pf_entityId; }
int8_t EntityLookAndRelativeMove::getDx() const { return _pf_dx; }
int8_t EntityLookAndRelativeMove::getDy() const { return _pf_dy; }
int8_t EntityLookAndRelativeMove::getDz() const { return _pf_dz; }
int8_t EntityLookAndRelativeMove::getYaw() const { return _pf_yaw; }
int8_t EntityLookAndRelativeMove::getPitch() const { return _pf_pitch; }

void EntityLookAndRelativeMove::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityLookAndRelativeMove::setDx(int8_t _val) { _pf_dx = _val; }
void EntityLookAndRelativeMove::setDy(int8_t _val) { _pf_dy = _val; }
void EntityLookAndRelativeMove::setDz(int8_t _val) { _pf_dz = _val; }
void EntityLookAndRelativeMove::setYaw(int8_t _val) { _pf_yaw = _val; }
void EntityLookAndRelativeMove::setPitch(int8_t _val) { _pf_pitch = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
