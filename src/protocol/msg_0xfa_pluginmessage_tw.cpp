#include "msg_0xfa_pluginmessage_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

PluginMessage::PluginMessage()
{
	_pf_packetId = static_cast<int8_t>(0xFA);
	_pf_initialized = false;
}

PluginMessage::PluginMessage(const String16& _channel, const ByteArray& _data)
	:	_pf_channel(_channel)
	,	_pf_data(_data)
{
	_pf_packetId = static_cast<int8_t>(0xFA);
	_pf_initialized = true;
}


size_t PluginMessage::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_channel);
	_offset = WriteByteArray(_dst, _offset, _pf_data);


	return _offset;
}

size_t PluginMessage::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	int16_t dataLen;
	_offset = ReadString16(_src, _offset, _pf_channel);
	_offset = ReadInt16(_src, _offset, dataLen);
	_offset = ReadByteArray(_src, _offset, dataLen, _pf_data);
	_pf_initialized = true;
	return _offset;
}

const String16& PluginMessage::getChannel() const { return _pf_channel; }
const ByteArray& PluginMessage::getData() const { return _pf_data; }

void PluginMessage::setChannel(const String16& _val) { _pf_channel = _val; }
void PluginMessage::setData(const ByteArray& _val) { _pf_data = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
