#ifndef _MSG_0XFC_ENCRYPTIONKEYRESPONSE_TW_H_
#define _MSG_0XFC_ENCRYPTIONKEYRESPONSE_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EncryptionKeyResponse : public BaseMessage
{
public:
	EncryptionKeyResponse();
	EncryptionKeyResponse(const ByteArray& _sharedSecret, const ByteArray& _verifyToken);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const ByteArray& getSharedSecret() const;
	const ByteArray& getVerifyToken() const;

	void setSharedSecret(const ByteArray& _val);
	void setVerifyToken(const ByteArray& _val);


private:
	ByteArray _pf_sharedSecret;
	ByteArray _pf_verifyToken;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XFC_ENCRYPTIONKEYRESPONSE_TW_H_