#include "msg_0xfd_encryptionkeyrequest_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EncryptionKeyRequest::EncryptionKeyRequest()
{
	_pf_packetId = static_cast<int8_t>(0xFD);
	_pf_initialized = false;
}

EncryptionKeyRequest::EncryptionKeyRequest(const String16& _serverId, const ByteArray& _publicKey, const ByteArray& _verifyToken)
	:	_pf_serverId(_serverId)
	,	_pf_publicKey(_publicKey)
	,	_pf_verifyToken(_verifyToken)
{
	_pf_packetId = static_cast<int8_t>(0xFD);
	_pf_initialized = true;
}


size_t EncryptionKeyRequest::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_serverId);
	_offset = WriteInt16(_dst, _offset, _pf_publicKey.size());
	_offset = WriteByteArray(_dst, _offset, _pf_publicKey);
	_offset = WriteInt16(_dst, _offset, _pf_verifyToken.size());
	_offset = WriteByteArray(_dst, _offset, _pf_verifyToken);


	return _offset;
}

size_t EncryptionKeyRequest::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	int16_t pubKeyLen, verTokLen;
	_offset = ReadString16(_src, _offset, _pf_serverId);
	_offset = ReadInt16(_src, _offset, pubKeyLen);
	_offset = ReadByteArray(_src, _offset, pubKeyLen, _pf_publicKey);
	_offset = ReadInt16(_src, _offset, verTokLen);
	_offset = ReadByteArray(_src, _offset, verTokLen, _pf_verifyToken);
	_pf_initialized = true;
	return _offset;
}

const String16& EncryptionKeyRequest::getServerId() const { return _pf_serverId; }
const ByteArray& EncryptionKeyRequest::getPublicKey() const { return _pf_publicKey; }
const ByteArray& EncryptionKeyRequest::getVerifyToken() const { return _pf_verifyToken; }

void EncryptionKeyRequest::setServerId(const String16& _val) { _pf_serverId = _val; }
void EncryptionKeyRequest::setPublicKey(const ByteArray& _val) { _pf_publicKey = _val; }
void EncryptionKeyRequest::setVerifyToken(const ByteArray& _val) { _pf_verifyToken = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
