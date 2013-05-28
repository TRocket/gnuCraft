#include "msg_0x22_entityteleport_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityTeleport::EntityTeleport()
{
	_pf_packetId = static_cast<int8_t>(0x22);
	_pf_initialized = false;
}

EntityTeleport::EntityTeleport(int32_t _entityId, int32_t _x, int32_t _y, int32_t _z, int8_t _yaw, int8_t _pitch)
	:	_pf_entityId(_entityId)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_yaw(_yaw)
	,	_pf_pitch(_pitch)
{
	_pf_packetId = static_cast<int8_t>(0x22);
	_pf_initialized = true;
}


size_t EntityTeleport::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt32(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt8(_dst, _offset, _pf_yaw);
	_offset = WriteInt8(_dst, _offset, _pf_pitch);


	return _offset;
}

size_t EntityTeleport::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_yaw);
	_offset = ReadInt8(_src, _offset, _pf_pitch);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityTeleport::getEntityId() const { return _pf_entityId; }
int32_t EntityTeleport::getX() const { return _pf_x; }
int32_t EntityTeleport::getY() const { return _pf_y; }
int32_t EntityTeleport::getZ() const { return _pf_z; }
int8_t EntityTeleport::getYaw() const { return _pf_yaw; }
int8_t EntityTeleport::getPitch() const { return _pf_pitch; }

void EntityTeleport::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityTeleport::setX(int32_t _val) { _pf_x = _val; }
void EntityTeleport::setY(int32_t _val) { _pf_y = _val; }
void EntityTeleport::setZ(int32_t _val) { _pf_z = _val; }
void EntityTeleport::setYaw(int8_t _val) { _pf_yaw = _val; }
void EntityTeleport::setPitch(int8_t _val) { _pf_pitch = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
