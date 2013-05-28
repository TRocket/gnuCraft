#include "msg_0x06_spawnposition_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SpawnPosition::SpawnPosition()
{
	_pf_packetId = static_cast<int8_t>(0x06);
	_pf_initialized = false;
}

SpawnPosition::SpawnPosition(int32_t _x, int32_t _y, int32_t _z)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
{
	_pf_packetId = static_cast<int8_t>(0x06);
	_pf_initialized = true;
}


size_t SpawnPosition::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt32(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);


	return _offset;
}

size_t SpawnPosition::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_pf_initialized = true;
	return _offset;
}

int32_t SpawnPosition::getX() const { return _pf_x; }
int32_t SpawnPosition::getY() const { return _pf_y; }
int32_t SpawnPosition::getZ() const { return _pf_z; }

void SpawnPosition::setX(int32_t _val) { _pf_x = _val; }
void SpawnPosition::setY(int32_t _val) { _pf_y = _val; }
void SpawnPosition::setZ(int32_t _val) { _pf_z = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
