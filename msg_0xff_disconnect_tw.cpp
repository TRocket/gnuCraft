#include "msg_0xff_disconnect_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Disconnect::Disconnect()
{
	_pf_packetId = static_cast<int8_t>(0xFF);
	_pf_initialized = false;
}

Disconnect::Disconnect(const String16& _reason)
	:	_pf_reason(_reason)
{
	_pf_packetId = static_cast<int8_t>(0xFF);
	_pf_initialized = true;
}


size_t Disconnect::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_reason);


	return _offset;
}

size_t Disconnect::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_reason);
	_pf_initialized = true;
	return _offset;
}

const String16& Disconnect::getReason() const { return _pf_reason; }

void Disconnect::setReason(const String16& _val) { _pf_reason = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
