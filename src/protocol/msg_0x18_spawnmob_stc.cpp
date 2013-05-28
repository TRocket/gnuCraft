#include "msg_0x18_spawnmob_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SpawnMob::SpawnMob()
{
	_pf_packetId = static_cast<int8_t>(0x18);
	_pf_initialized = false;
}

SpawnMob::SpawnMob(int32_t _entityId, int8_t _type, int32_t _x, int32_t _y, int32_t _z, int8_t _pitch, int8_t _headPitch, int8_t _yaw, int16_t _xVelocity, int16_t _yVelocity, int16_t _zVelocity)
	:	_pf_entityId(_entityId)
	,	_pf_type(_type)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_pitch(_pitch)
	,	_pf_headPitch(_headPitch)
	,	_pf_yaw(_yaw)
	,	_pf_xVelocity(_xVelocity)
	,	_pf_yVelocity(_yVelocity)
	,	_pf_zVelocity(_zVelocity)
{
	_pf_packetId = static_cast<int8_t>(0x18);
	_pf_initialized = true;
}


size_t SpawnMob::serialize(Buffer& _dst, size_t _offset)
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
	_offset = WriteInt8(_dst, _offset, _pf_headPitch);
	_offset = WriteInt8(_dst, _offset, _pf_yaw);
	_offset = WriteInt16(_dst, _offset, _pf_xVelocity);
	_offset = WriteInt16(_dst, _offset, _pf_yVelocity);
	_offset = WriteInt16(_dst, _offset, _pf_zVelocity);


	return _offset;
}

size_t SpawnMob::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_type);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_pitch);
	_offset = ReadInt8(_src, _offset, _pf_headPitch);
	_offset = ReadInt8(_src, _offset, _pf_yaw);
	_offset = ReadInt16(_src, _offset, _pf_xVelocity);
	_offset = ReadInt16(_src, _offset, _pf_yVelocity);
	_offset = ReadInt16(_src, _offset, _pf_zVelocity);
	_offset = _pf_metadata.deserialize(_src, _offset);

	_pf_initialized = true;
	return _offset;
}

int32_t SpawnMob::getEntityId() const { return _pf_entityId; }
int8_t SpawnMob::getType() const { return _pf_type; }
int32_t SpawnMob::getX() const { return _pf_x; }
int32_t SpawnMob::getY() const { return _pf_y; }
int32_t SpawnMob::getZ() const { return _pf_z; }
int8_t SpawnMob::getPitch() const { return _pf_pitch; }
int8_t SpawnMob::getHeadPitch() const { return _pf_headPitch; }
int8_t SpawnMob::getYaw() const { return _pf_yaw; }
int16_t SpawnMob::getXVelocity() const { return _pf_xVelocity; }
int16_t SpawnMob::getYVelocity() const { return _pf_yVelocity; }
int16_t SpawnMob::getZVelocity() const { return _pf_zVelocity; }

void SpawnMob::setEntityId(int32_t _val) { _pf_entityId = _val; }
void SpawnMob::setType(int8_t _val) { _pf_type = _val; }
void SpawnMob::setX(int32_t _val) { _pf_x = _val; }
void SpawnMob::setY(int32_t _val) { _pf_y = _val; }
void SpawnMob::setZ(int32_t _val) { _pf_z = _val; }
void SpawnMob::setPitch(int8_t _val) { _pf_pitch = _val; }
void SpawnMob::setHeadPitch(int8_t _val) { _pf_headPitch = _val; }
void SpawnMob::setYaw(int8_t _val) { _pf_yaw = _val; }
void SpawnMob::setXVelocity(int16_t _val) { _pf_xVelocity = _val; }
void SpawnMob::setYVelocity(int16_t _val) { _pf_yVelocity = _val; }
void SpawnMob::setZVelocity(int16_t _val) { _pf_zVelocity = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
