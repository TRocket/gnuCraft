#include "msg_0xfc_encryptionkeyresponse_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EncryptionKeyResponse::EncryptionKeyResponse()
{
	_pf_packetId = static_cast<int8_t>(0xFC);
	_pf_initialized = false;
}

EncryptionKeyResponse::EncryptionKeyResponse(const ByteArray& _sharedSecret, const ByteArray& _verifyToken)
	:	_pf_sharedSecret(_sharedSecret)
	,	_pf_verifyToken(_verifyToken)
{
	_pf_packetId = static_cast<int8_t>(0xFC);
	_pf_initialized = true;
}


size_t EncryptionKeyResponse::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt16(_dst, _offset, _pf_sharedSecret.size());
	_offset = WriteByteArray(_dst, _offset, _pf_verifyToken);
	_offset = WriteInt16(_dst, _offset, _pf_sharedSecret.size());
	_offset = WriteByteArray(_dst, _offset, _pf_verifyToken);


	return _offset;
}

size_t EncryptionKeyResponse::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	int16_t sharedSecretLen, verTokLen;

	_offset = ReadInt16(_src, _offset, sharedSecretLen);
	_offset = ReadByteArray(_src, _offset, sharedSecretLen, _pf_sharedSecret);
	_offset = ReadInt16(_src, _offset, verTokLen);
	_offset = ReadByteArray(_src, _offset, verTokLen, _pf_verifyToken);
	_pf_initialized = true;
	return _offset;
}

const ByteArray& EncryptionKeyResponse::getSharedSecret() const { return _pf_sharedSecret; }
const ByteArray& EncryptionKeyResponse::getVerifyToken() const { return _pf_verifyToken; }

void EncryptionKeyResponse::setSharedSecret(const ByteArray& _val) { _pf_sharedSecret = _val; }
void EncryptionKeyResponse::setVerifyToken(const ByteArray& _val) { _pf_verifyToken = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
