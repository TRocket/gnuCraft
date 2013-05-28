#include "msg_0x02_handshake_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Handshake::Handshake()
{
	_pf_packetId = static_cast<int8_t>(0x02);
	_pf_initialized = false;
}

Handshake::Handshake(int8_t _protVer, const String16& _username, const String16& _host, int32_t _port)
	:	_pf_protVer(_protVer)
	,	_pf_username(_username)
	,	_pf_host(_host)
	,	_pf_port(_port)
{
	_pf_packetId = static_cast<int8_t>(0x02);
	_pf_initialized = true;
}


size_t Handshake::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_protVer);
	_offset = WriteString16(_dst, _offset, _pf_username);
	_offset = WriteString16(_dst, _offset, _pf_host);
	_offset = WriteInt32(_dst, _offset, _pf_port);


	return _offset;
}

size_t Handshake::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_protVer);
	_offset = ReadString16(_src, _offset, _pf_username);
	_offset = ReadString16(_src, _offset, _pf_host);
	_offset = ReadInt32(_src, _offset, _pf_port);
	_pf_initialized = true;
	return _offset;
}

int8_t Handshake::getProtVer() const { return _pf_protVer; }
const String16& Handshake::getUsername() const { return _pf_username; }
const String16& Handshake::getHost() const { return _pf_host; }
int32_t Handshake::getPort() const { return _pf_port; }

void Handshake::setProtVer(int8_t _val) { _pf_protVer = _val; }
void Handshake::setUsername(const String16& _val) { _pf_username = _val; }
void Handshake::setHost(const String16& _val) { _pf_host = _val; }
void Handshake::setPort(int32_t _val) { _pf_port = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
