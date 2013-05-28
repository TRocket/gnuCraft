#include "objectdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ObjectData::ObjectData()
{
	//_pf_packetId = static_cast<int8_t>(0xxx);
	_pf_initialized = false;
}

ObjectData::ObjectData(int32_t _intField, int16_t _xSpeed, int16_t _ySpeed, int16_t _zSpeed)
	:	_pf_intField(_intField)
	,	_pf_xSpeed(_xSpeed)
	,	_pf_ySpeed(_ySpeed)
	,	_pf_zSpeed(_zSpeed)
{
	//_pf_packetId = static_cast<int8_t>(0xxx);
	_pf_initialized = true;
}


size_t ObjectData::serialize(Buffer& _dst, size_t _offset)
{
	/*_pm_checkInit();
	_dst.clear();

	_pm_serializeInt8(_pf_packetId, _dst);
	_pm_serializeInt32(_pf_intField, _dst);
	_pm_serializeInt16(_pf_xSpeed, _dst);
	_pm_serializeInt16(_pf_ySpeed, _dst);
	_pm_serializeInt16(_pf_zSpeed, _dst);*/
	throw "NYI";

	return 0;
}

size_t ObjectData::deserialize(const Buffer& _src, size_t _offset)
{
	//_pm_checkPacketId(_src);

	_offset = ReadInt32(_src, _offset, _pf_intField);

	if(_pf_intField != 0)
	{
		_offset = ReadInt16(_src, _offset, _pf_xSpeed);
		_offset = ReadInt16(_src, _offset, _pf_ySpeed);
		_offset = ReadInt16(_src, _offset, _pf_zSpeed);
	}

	_pf_initialized = true;

	return _offset;
}

int32_t ObjectData::getIntField() const { return _pf_intField; }
int16_t ObjectData::getXSpeed() const { return _pf_xSpeed; }
int16_t ObjectData::getYSpeed() const { return _pf_ySpeed; }
int16_t ObjectData::getZSpeed() const { return _pf_zSpeed; }

void ObjectData::setIntField(int32_t _val) { _pf_intField = _val; }
void ObjectData::setXSpeed(int16_t _val) { _pf_xSpeed = _val; }
void ObjectData::setYSpeed(int16_t _val) { _pf_ySpeed = _val; }
void ObjectData::setZSpeed(int16_t _val) { _pf_zSpeed = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
