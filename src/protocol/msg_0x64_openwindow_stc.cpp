#include "msg_0x64_openwindow_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

OpenWindow::OpenWindow()
{
	_pf_packetId = static_cast<int8_t>(0x64);
	_pf_initialized = false;
}

OpenWindow::OpenWindow(int8_t _windowId, int8_t _inventoryType, const String16& _windowTitle, int8_t _numOfSlots, bool _useProvidedWindowTitle)
	:	_pf_windowId(_windowId)
	,	_pf_inventoryType(_inventoryType)
	,	_pf_windowTitle(_windowTitle)
	,	_pf_numOfSlots(_numOfSlots)
	,	_pf_useProvidedWindowTitle(_useProvidedWindowTitle)
{
	_pf_packetId = static_cast<int8_t>(0x64);
	_pf_initialized = true;
}


size_t OpenWindow::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_windowId);
	_offset = WriteInt8(_dst, _offset, _pf_inventoryType);
	_offset = WriteString16(_dst, _offset, _pf_windowTitle);
	_offset = WriteInt8(_dst, _offset, _pf_numOfSlots);
	_offset = WriteBool(_dst, _offset, _pf_useProvidedWindowTitle);


	return _offset;
}

size_t OpenWindow::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_windowId);
	_offset = ReadInt8(_src, _offset, _pf_inventoryType);
	_offset = ReadString16(_src, _offset, _pf_windowTitle);
	_offset = ReadInt8(_src, _offset, _pf_numOfSlots);
	_offset = ReadBool(_src, _offset, _pf_useProvidedWindowTitle);
	_pf_initialized = true;
	return _offset;
}

int8_t OpenWindow::getWindowId() const { return _pf_windowId; }
int8_t OpenWindow::getInventoryType() const { return _pf_inventoryType; }
const String16& OpenWindow::getWindowTitle() const { return _pf_windowTitle; }
int8_t OpenWindow::getNumOfSlots() const { return _pf_numOfSlots; }
bool OpenWindow::getUseProvidedWindowTitle() const { return _pf_useProvidedWindowTitle; }

void OpenWindow::setWindowId(int8_t _val) { _pf_windowId = _val; }
void OpenWindow::setInventoryType(int8_t _val) { _pf_inventoryType = _val; }
void OpenWindow::setWindowTitle(const String16& _val) { _pf_windowTitle = _val; }
void OpenWindow::setNumOfSlots(int8_t _val) { _pf_numOfSlots = _val; }
void OpenWindow::setUseProvidedWindowTitle(bool _val) { _pf_useProvidedWindowTitle = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
