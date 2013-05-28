#include "msg_0x00_keepalive_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

KeepAlive::KeepAlive()
{
	_pf_packetId = static_cast<int8_t>(0x00);
	_pf_initialized = false;
}

KeepAlive::KeepAlive(int32_t _keepAliveId)
	:	_pf_keepAliveId(_keepAliveId)
{
	_pf_packetId = static_cast<int8_t>(0x00);
	_pf_initialized = true;
}


size_t KeepAlive::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_keepAliveId);


	return _offset;
}

size_t KeepAlive::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_keepAliveId);
	_pf_initialized = true;
	return _offset;
}

int32_t KeepAlive::getKeepAliveId() const { return _pf_keepAliveId; }

void KeepAlive::setKeepAliveId(int32_t _val) { _pf_keepAliveId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
