#include "msg_0xcb_tabcomplete_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

TabComplete::TabComplete()
{
	_pf_packetId = static_cast<int8_t>(0xCB);
	_pf_initialized = false;
}

TabComplete::TabComplete(const String16& _text)
	:	_pf_text(_text)
{
	_pf_packetId = static_cast<int8_t>(0xCB);
	_pf_initialized = true;
}


size_t TabComplete::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_text);


	return _offset;
}

size_t TabComplete::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_text);
	_pf_initialized = true;
	return _offset;
}

const String16& TabComplete::getText() const { return _pf_text; }

void TabComplete::setText(const String16& _val) { _pf_text = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
