#include "msg_0x1a_spawnexperienceorb_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SpawnExperienceOrb::SpawnExperienceOrb()
{
	_pf_packetId = static_cast<int8_t>(0x1A);
	_pf_initialized = false;
}

SpawnExperienceOrb::SpawnExperienceOrb(int32_t _entityId, int32_t _x, int32_t _y, int32_t _z, int16_t _count)
	:	_pf_entityId(_entityId)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_count(_count)
{
	_pf_packetId = static_cast<int8_t>(0x1A);
	_pf_initialized = true;
}


size_t SpawnExperienceOrb::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt32(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt16(_dst, _offset, _pf_count);


	return _offset;
}

size_t SpawnExperienceOrb::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt16(_src, _offset, _pf_count);
	_pf_initialized = true;
	return _offset;
}

int32_t SpawnExperienceOrb::getEntityId() const { return _pf_entityId; }
int32_t SpawnExperienceOrb::getX() const { return _pf_x; }
int32_t SpawnExperienceOrb::getY() const { return _pf_y; }
int32_t SpawnExperienceOrb::getZ() const { return _pf_z; }
int16_t SpawnExperienceOrb::getCount() const { return _pf_count; }

void SpawnExperienceOrb::setEntityId(int32_t _val) { _pf_entityId = _val; }
void SpawnExperienceOrb::setX(int32_t _val) { _pf_x = _val; }
void SpawnExperienceOrb::setY(int32_t _val) { _pf_y = _val; }
void SpawnExperienceOrb::setZ(int32_t _val) { _pf_z = _val; }
void SpawnExperienceOrb::setCount(int16_t _val) { _pf_count = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
