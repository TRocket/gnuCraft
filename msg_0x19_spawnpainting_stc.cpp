#include "msg_0x19_spawnpainting_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SpawnPainting::SpawnPainting()
{
	_pf_packetId = static_cast<int8_t>(0x19);
	_pf_initialized = false;
}

SpawnPainting::SpawnPainting(int32_t _entityId, const String16& _title, int32_t _x, int32_t _y, int32_t _z, int32_t _direction)
	:	_pf_entityId(_entityId)
	,	_pf_title(_title)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_direction(_direction)
{
	_pf_packetId = static_cast<int8_t>(0x19);
	_pf_initialized = true;
}


size_t SpawnPainting::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteString16(_dst, _offset, _pf_title);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt32(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt32(_dst, _offset, _pf_direction);


	return _offset;
}

size_t SpawnPainting::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadString16(_src, _offset, _pf_title);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt32(_src, _offset, _pf_direction);
	_pf_initialized = true;
	return _offset;
}

int32_t SpawnPainting::getEntityId() const { return _pf_entityId; }
const String16& SpawnPainting::getTitle() const { return _pf_title; }
int32_t SpawnPainting::getX() const { return _pf_x; }
int32_t SpawnPainting::getY() const { return _pf_y; }
int32_t SpawnPainting::getZ() const { return _pf_z; }
int32_t SpawnPainting::getDirection() const { return _pf_direction; }

void SpawnPainting::setEntityId(int32_t _val) { _pf_entityId = _val; }
void SpawnPainting::setTitle(const String16& _val) { _pf_title = _val; }
void SpawnPainting::setX(int32_t _val) { _pf_x = _val; }
void SpawnPainting::setY(int32_t _val) { _pf_y = _val; }
void SpawnPainting::setZ(int32_t _val) { _pf_z = _val; }
void SpawnPainting::setDirection(int32_t _val) { _pf_direction = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
