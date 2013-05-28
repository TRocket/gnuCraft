#ifndef _MSG_0X02_HANDSHAKE_CTS_H_
#define _MSG_0X02_HANDSHAKE_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Handshake : public BaseMessage
{
public:
	Handshake();
	Handshake(int8_t _protVer, const String16& _username, const String16& _host, int32_t _port);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getProtVer() const;
	const String16& getUsername() const;
	const String16& getHost() const;
	int32_t getPort() const;

	void setProtVer(int8_t _val);
	void setUsername(const String16& _val);
	void setHost(const String16& _val);
	void setPort(int32_t _val);


private:
	int8_t _pf_protVer;
	String16 _pf_username;
	String16 _pf_host;
	int32_t _pf_port;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X02_HANDSHAKE_CTS_H_