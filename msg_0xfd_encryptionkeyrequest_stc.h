#ifndef _MSG_0XFD_ENCRYPTIONKEYREQUEST_STC_H_
#define _MSG_0XFD_ENCRYPTIONKEYREQUEST_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EncryptionKeyRequest : public BaseMessage
{
public:
	EncryptionKeyRequest();
	EncryptionKeyRequest(const String16& _serverId, const ByteArray& _publicKey, const ByteArray& _verifyToken);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getServerId() const;
	const ByteArray& getPublicKey() const;
	const ByteArray& getVerifyToken() const;

	void setServerId(const String16& _val);
	void setPublicKey(const ByteArray& _val);
	void setVerifyToken(const ByteArray& _val);


private:
	String16 _pf_serverId;
	ByteArray _pf_publicKey;
	ByteArray _pf_verifyToken;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XFD_ENCRYPTIONKEYREQUEST_STC_H_