#include "msg_0x17_spawnobject_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SpawnObject::SpawnObject()
{
	_pf_packetId = static_cast<int8_t>(0x17);
	_pf_initialized = false;
}

SpawnObject::SpawnObject(int32_t _entityId, int8_t _type, int32_t _x, int32_t _y, int32_t _z, int8_t _pitch, int8_t _yaw)
	:	_pf_entityId(_entityId)
	,	_pf_type(_type)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_pitch(_pitch)
	,	_pf_yaw(_yaw)
{
	_pf_packetId = static_cast<int8_t>(0x17);
	_pf_initialized = true;
}


size_t SpawnObject::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_type);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt32(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt8(_dst, _offset, _pf_pitch);
	_offset = WriteInt8(_dst, _offset, _pf_yaw);
	// Сделать запись Object data


	return _offset;
}

size_t SpawnObject::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_type);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_pitch);
	_offset = ReadInt8(_src, _offset, _pf_yaw);
	_offset = _pf_objectData.deserialize(_src, _offset);

	_pf_initialized = true;
	return _offset;
}

int32_t SpawnObject::getEntityId() const { return _pf_entityId; }
int8_t SpawnObject::getType() const { return _pf_type; }
int32_t SpawnObject::getX() const { return _pf_x; }
int32_t SpawnObject::getY() const { return _pf_y; }
int32_t SpawnObject::getZ() const { return _pf_z; }
int8_t SpawnObject::getPitch() const { return _pf_pitch; }
int8_t SpawnObject::getYaw() const { return _pf_yaw; }

void SpawnObject::setEntityId(int32_t _val) { _pf_entityId = _val; }
void SpawnObject::setType(int8_t _val) { _pf_type = _val; }
void SpawnObject::setX(int32_t _val) { _pf_x = _val; }
void SpawnObject::setY(int32_t _val) { _pf_y = _val; }
void SpawnObject::setZ(int32_t _val) { _pf_z = _val; }
void SpawnObject::setPitch(int8_t _val) { _pf_pitch = _val; }
void SpawnObject::setYaw(int8_t _val) { _pf_yaw = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
