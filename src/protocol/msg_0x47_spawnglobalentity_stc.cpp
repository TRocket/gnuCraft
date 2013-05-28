#include "msg_0x47_spawnglobalentity_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SpawnGlobalEntity::SpawnGlobalEntity()
{
	_pf_packetId = static_cast<int8_t>(0x47);
	_pf_initialized = false;
}

SpawnGlobalEntity::SpawnGlobalEntity(int32_t _entityId, int8_t _type, int32_t _x, int32_t _y, int32_t _z)
	:	_pf_entityId(_entityId)
	,	_pf_type(_type)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
{
	_pf_packetId = static_cast<int8_t>(0x47);
	_pf_initialized = true;
}


size_t SpawnGlobalEntity::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_type);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt32(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);


	return _offset;
}

size_t SpawnGlobalEntity::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_type);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_pf_initialized = true;
	return _offset;
}

int32_t SpawnGlobalEntity::getEntityId() const { return _pf_entityId; }
int8_t SpawnGlobalEntity::getType() const { return _pf_type; }
int32_t SpawnGlobalEntity::getX() const { return _pf_x; }
int32_t SpawnGlobalEntity::getY() const { return _pf_y; }
int32_t SpawnGlobalEntity::getZ() const { return _pf_z; }

void SpawnGlobalEntity::setEntityId(int32_t _val) { _pf_entityId = _val; }
void SpawnGlobalEntity::setType(int8_t _val) { _pf_type = _val; }
void SpawnGlobalEntity::setX(int32_t _val) { _pf_x = _val; }
void SpawnGlobalEntity::setY(int32_t _val) { _pf_y = _val; }
void SpawnGlobalEntity::setZ(int32_t _val) { _pf_z = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
