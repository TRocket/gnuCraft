#include "msg_0x67_setslot_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SetSlot::SetSlot()
{
	_pf_packetId = static_cast<int8_t>(0x67);
	_pf_initialized = false;
}

SetSlot::SetSlot(int8_t _windowId, int16_t _slotNum)
	:	_pf_windowId(_windowId)
	,	_pf_slotNum(_slotNum)
{
	_pf_packetId = static_cast<int8_t>(0x67);
	_pf_initialized = true;
}


size_t SetSlot::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_windowId);
	_offset = WriteInt16(_dst, _offset, _pf_slotNum);


	return _offset;
}

size_t SetSlot::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_windowId);
	_offset = ReadInt16(_src, _offset, _pf_slotNum);

	_offset = SlotData().deserialize(_src, _offset);

	_pf_initialized = true;
	return _offset;
}

int8_t SetSlot::getWindowId() const { return _pf_windowId; }
int16_t SetSlot::getSlotNum() const { return _pf_slotNum; }

void SetSlot::setWindowId(int8_t _val) { _pf_windowId = _val; }
void SetSlot::setSlotNum(int16_t _val) { _pf_slotNum = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
