#include "msg_0x69_updatewindowproperty_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

UpdateWindowProperty::UpdateWindowProperty()
{
	_pf_packetId = static_cast<int8_t>(0x69);
	_pf_initialized = false;
}

UpdateWindowProperty::UpdateWindowProperty(int8_t _windowId, int16_t _property, int16_t _value)
	:	_pf_windowId(_windowId)
	,	_pf_property(_property)
	,	_pf_value(_value)
{
	_pf_packetId = static_cast<int8_t>(0x69);
	_pf_initialized = true;
}


size_t UpdateWindowProperty::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_windowId);
	_offset = WriteInt16(_dst, _offset, _pf_property);
	_offset = WriteInt16(_dst, _offset, _pf_value);


	return _offset;
}

size_t UpdateWindowProperty::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_windowId);
	_offset = ReadInt16(_src, _offset, _pf_property);
	_offset = ReadInt16(_src, _offset, _pf_value);
	_pf_initialized = true;
	return _offset;
}

int8_t UpdateWindowProperty::getWindowId() const { return _pf_windowId; }
int16_t UpdateWindowProperty::getProperty() const { return _pf_property; }
int16_t UpdateWindowProperty::getValue() const { return _pf_value; }

void UpdateWindowProperty::setWindowId(int8_t _val) { _pf_windowId = _val; }
void UpdateWindowProperty::setProperty(int16_t _val) { _pf_property = _val; }
void UpdateWindowProperty::setValue(int16_t _val) { _pf_value = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
