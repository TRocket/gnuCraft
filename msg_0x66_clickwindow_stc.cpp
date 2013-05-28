#include "msg_0x66_clickwindow_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ClickWindow::ClickWindow()
{
	_pf_packetId = static_cast<int8_t>(0x66);
	_pf_initialized = false;
}

ClickWindow::ClickWindow(int8_t _windowId, int16_t _slot, int8_t _button, int16_t _actionNumber, int8_t _mode, SlotData _clickedItem)
	:	_pf_windowId(_windowId)
	,	_pf_slot(_slot)
	,	_pf_button(_button)
	,	_pf_actionNumber(_actionNumber)
	,	_pf_mode(_mode)
	,	_pf_clickedItem(_clickedItem)
{
	_pf_packetId = static_cast<int8_t>(0x66);
	_pf_initialized = true;
}


size_t ClickWindow::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_windowId);
	_offset = WriteInt16(_dst, _offset, _pf_slot);
	_offset = WriteInt8(_dst, _offset, _pf_button);
	_offset = WriteInt16(_dst, _offset, _pf_actionNumber);
	_offset = WriteInt8(_dst, _offset, _pf_mode);
	//_offset = WriteSlotData(_dst, _offset, _pf_clickedItem);
	_offset = _pf_clickedItem.serialize(_dst, _offset);


	return _offset;
}

size_t ClickWindow::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_windowId);
	_offset = ReadInt16(_src, _offset, _pf_slot);
	_offset = ReadInt8(_src, _offset, _pf_button);
	_offset = ReadInt16(_src, _offset, _pf_actionNumber);
	_offset = ReadInt8(_src, _offset, _pf_mode);
	//_offset = ReadSlotData(_src, _offset, _pf_clickedItem);
	_offset = _pf_clickedItem.deserialize(_src, _offset);
	_pf_initialized = true;
	return _offset;
}

int8_t ClickWindow::getWindowId() const { return _pf_windowId; }
int16_t ClickWindow::getSlot() const { return _pf_slot; }
int8_t ClickWindow::getButton() const { return _pf_button; }
int16_t ClickWindow::getActionNumber() const { return _pf_actionNumber; }
int8_t ClickWindow::getMode() const { return _pf_mode; }
SlotData ClickWindow::getClickedItem() const { return _pf_clickedItem; }

void ClickWindow::setWindowId(int8_t _val) { _pf_windowId = _val; }
void ClickWindow::setSlot(int16_t _val) { _pf_slot = _val; }
void ClickWindow::setButton(int8_t _val) { _pf_button = _val; }
void ClickWindow::setActionNumber(int16_t _val) { _pf_actionNumber = _val; }
void ClickWindow::setMode(int8_t _val) { _pf_mode = _val; }
void ClickWindow::setClickedItem(SlotData _val) { _pf_clickedItem = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
