#include "msg_0x1c_entityvelocity_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityVelocity::EntityVelocity()
{
	_pf_packetId = static_cast<int8_t>(0x1C);
	_pf_initialized = false;
}

EntityVelocity::EntityVelocity(int32_t _entityId, int16_t _xVelocity, int16_t _yVeclosity, int16_t _zVelocity)
	:	_pf_entityId(_entityId)
	,	_pf_xVelocity(_xVelocity)
	,	_pf_yVeclosity(_yVeclosity)
	,	_pf_zVelocity(_zVelocity)
{
	_pf_packetId = static_cast<int8_t>(0x1C);
	_pf_initialized = true;
}


size_t EntityVelocity::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt16(_dst, _offset, _pf_xVelocity);
	_offset = WriteInt16(_dst, _offset, _pf_yVeclosity);
	_offset = WriteInt16(_dst, _offset, _pf_zVelocity);


	return _offset;
}

size_t EntityVelocity::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt16(_src, _offset, _pf_xVelocity);
	_offset = ReadInt16(_src, _offset, _pf_yVeclosity);
	_offset = ReadInt16(_src, _offset, _pf_zVelocity);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityVelocity::getEntityId() const { return _pf_entityId; }
int16_t EntityVelocity::getXVelocity() const { return _pf_xVelocity; }
int16_t EntityVelocity::getYVeclosity() const { return _pf_yVeclosity; }
int16_t EntityVelocity::getZVelocity() const { return _pf_zVelocity; }

void EntityVelocity::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityVelocity::setXVelocity(int16_t _val) { _pf_xVelocity = _val; }
void EntityVelocity::setYVeclosity(int16_t _val) { _pf_yVeclosity = _val; }
void EntityVelocity::setZVelocity(int16_t _val) { _pf_zVelocity = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
