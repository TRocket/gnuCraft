#include "msg_0x65_closewindow_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

CloseWIndow::CloseWIndow()
{
	_pf_packetId = static_cast<int8_t>(0x65);
	_pf_initialized = false;
}

CloseWIndow::CloseWIndow(int8_t _windowId)
	:	_pf_windowId(_windowId)
{
	_pf_packetId = static_cast<int8_t>(0x65);
	_pf_initialized = true;
}


size_t CloseWIndow::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_windowId);


	return _offset;
}

size_t CloseWIndow::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_windowId);
	_pf_initialized = true;
	return _offset;
}

int8_t CloseWIndow::getWindowId() const { return _pf_windowId; }

void CloseWIndow::setWindowId(int8_t _val) { _pf_windowId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
