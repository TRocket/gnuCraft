#include "msg_0x03_chatmessage_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ChatMessage::ChatMessage()
{
	_pf_packetId = static_cast<int8_t>(0x03);
	_pf_initialized = false;
}

ChatMessage::ChatMessage(const String16& _text)
	:	_pf_text(_text)
{
	_pf_packetId = static_cast<int8_t>(0x03);
	_pf_initialized = true;
}


size_t ChatMessage::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_text);


	return _offset;
}

size_t ChatMessage::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_text);
	_pf_initialized = true;
	return _offset;
}

const String16& ChatMessage::getText() const { return _pf_text; }

void ChatMessage::setText(const String16& _val) { _pf_text = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
