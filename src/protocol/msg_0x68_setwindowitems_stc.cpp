#include "msg_0x68_setwindowitems_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SetWindowItems::SetWindowItems()
{
	_pf_packetId = static_cast<int8_t>(0x68);
	_pf_initialized = false;
}

SetWindowItems::SetWindowItems(int8_t _windowId, int16_t _slotsCount)
	:	_pf_windowId(_windowId)
	,	_pf_slotsCount(_slotsCount)
{
	_pf_packetId = static_cast<int8_t>(0x68);
	_pf_initialized = true;
}


size_t SetWindowItems::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_windowId);
	_offset = WriteInt16(_dst, _offset, _pf_slotsCount);


	return _offset;
}

size_t SetWindowItems::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_windowId);
	_offset = ReadInt16(_src, _offset, _pf_slotsCount);

	for(int i = 0; i < _pf_slotsCount; ++i)
		_offset = SlotData().deserialize(_src, _offset);

	_pf_initialized = true;
	return _offset;
}

int8_t SetWindowItems::getWindowId() const { return _pf_windowId; }
int16_t SetWindowItems::getSlotsCount() const { return _pf_slotsCount; }

void SetWindowItems::setWindowId(int8_t _val) { _pf_windowId = _val; }
void SetWindowItems::setSlotsCount(int16_t _val) { _pf_slotsCount = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
