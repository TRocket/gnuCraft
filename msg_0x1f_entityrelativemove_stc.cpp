#include "msg_0x1f_entityrelativemove_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityRelativeMove::EntityRelativeMove()
{
	_pf_packetId = static_cast<int8_t>(0x1F);
	_pf_initialized = false;
}

EntityRelativeMove::EntityRelativeMove(int32_t _entityId, int8_t _dx, int8_t _dy, int8_t _dz)
	:	_pf_entityId(_entityId)
	,	_pf_dx(_dx)
	,	_pf_dy(_dy)
	,	_pf_dz(_dz)
{
	_pf_packetId = static_cast<int8_t>(0x1F);
	_pf_initialized = true;
}


size_t EntityRelativeMove::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_dx);
	_offset = WriteInt8(_dst, _offset, _pf_dy);
	_offset = WriteInt8(_dst, _offset, _pf_dz);


	return _offset;
}

size_t EntityRelativeMove::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_dx);
	_offset = ReadInt8(_src, _offset, _pf_dy);
	_offset = ReadInt8(_src, _offset, _pf_dz);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityRelativeMove::getEntityId() const { return _pf_entityId; }
int8_t EntityRelativeMove::getDx() const { return _pf_dx; }
int8_t EntityRelativeMove::getDy() const { return _pf_dy; }
int8_t EntityRelativeMove::getDz() const { return _pf_dz; }

void EntityRelativeMove::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityRelativeMove::setDx(int8_t _val) { _pf_dx = _val; }
void EntityRelativeMove::setDy(int8_t _val) { _pf_dy = _val; }
void EntityRelativeMove::setDz(int8_t _val) { _pf_dz = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
