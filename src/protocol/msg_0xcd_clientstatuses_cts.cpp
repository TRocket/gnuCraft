#include "msg_0xcd_clientstatuses_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ClientStatuses::ClientStatuses()
{
	_pf_packetId = static_cast<int8_t>(0xCD);
	_pf_initialized = false;
}

ClientStatuses::ClientStatuses(int8_t _payload)
	:	_pf_payload(_payload)
{
	_pf_packetId = static_cast<int8_t>(0xCD);
	_pf_initialized = true;
}


size_t ClientStatuses::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_payload);


	return _offset;
}

size_t ClientStatuses::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_payload);
	_pf_initialized = true;
	return _offset;
}

int8_t ClientStatuses::getPayload() const { return _pf_payload; }

void ClientStatuses::setPayload(int8_t _val) { _pf_payload = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
