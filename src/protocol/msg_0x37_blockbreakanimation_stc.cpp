#include "msg_0x37_blockbreakanimation_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

BlockBreakAnimation::BlockBreakAnimation()
{
	_pf_packetId = static_cast<int8_t>(0x37);
	_pf_initialized = false;
}

BlockBreakAnimation::BlockBreakAnimation(int32_t _EntityId, int32_t _x, int32_t _y, int32_t _z, int8_t _destroyStage)
	:	_pf_EntityId(_EntityId)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_destroyStage(_destroyStage)
{
	_pf_packetId = static_cast<int8_t>(0x37);
	_pf_initialized = true;
}


size_t BlockBreakAnimation::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_EntityId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt32(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt8(_dst, _offset, _pf_destroyStage);


	return _offset;
}

size_t BlockBreakAnimation::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_EntityId);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_destroyStage);
	_pf_initialized = true;
	return _offset;
}

int32_t BlockBreakAnimation::getEntityId() const { return _pf_EntityId; }
int32_t BlockBreakAnimation::getX() const { return _pf_x; }
int32_t BlockBreakAnimation::getY() const { return _pf_y; }
int32_t BlockBreakAnimation::getZ() const { return _pf_z; }
int8_t BlockBreakAnimation::getDestroyStage() const { return _pf_destroyStage; }

void BlockBreakAnimation::setEntityId(int32_t _val) { _pf_EntityId = _val; }
void BlockBreakAnimation::setX(int32_t _val) { _pf_x = _val; }
void BlockBreakAnimation::setY(int32_t _val) { _pf_y = _val; }
void BlockBreakAnimation::setZ(int32_t _val) { _pf_z = _val; }
void BlockBreakAnimation::setDestroyStage(int8_t _val) { _pf_destroyStage = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
