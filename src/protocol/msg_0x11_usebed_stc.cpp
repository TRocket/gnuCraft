#include "msg_0x11_usebed_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

UseBed::UseBed()
{
	_pf_packetId = static_cast<int8_t>(0x11);
	_pf_initialized = false;
}

UseBed::UseBed(int32_t _entityId, int8_t _unknown, int32_t _x, int8_t _y, int32_t _z)
	:	_pf_entityId(_entityId)
	,	_pf_unknown(_unknown)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
{
	_pf_packetId = static_cast<int8_t>(0x11);
	_pf_initialized = true;
}


size_t UseBed::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_unknown);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt8(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);


	return _offset;
}

size_t UseBed::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_unknown);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt8(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_pf_initialized = true;
	return _offset;
}

int32_t UseBed::getEntityId() const { return _pf_entityId; }
int8_t UseBed::getUnknown() const { return _pf_unknown; }
int32_t UseBed::getX() const { return _pf_x; }
int8_t UseBed::getY() const { return _pf_y; }
int32_t UseBed::getZ() const { return _pf_z; }

void UseBed::setEntityId(int32_t _val) { _pf_entityId = _val; }
void UseBed::setUnknown(int8_t _val) { _pf_unknown = _val; }
void UseBed::setX(int32_t _val) { _pf_x = _val; }
void UseBed::setY(int8_t _val) { _pf_y = _val; }
void UseBed::setZ(int32_t _val) { _pf_z = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
