#ifndef _MSG_0XFF_DISCONNECT_TW_H_
#define _MSG_0XFF_DISCONNECT_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Disconnect : public BaseMessage
{
public:
	Disconnect();
	Disconnect(const String16& _reason);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getReason() const;

	void setReason(const String16& _val);


private:
	String16 _pf_reason;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XFF_DISCONNECT_TW_H_