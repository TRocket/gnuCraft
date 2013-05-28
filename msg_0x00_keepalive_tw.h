#ifndef _MSG_0X00_KEEPALIVE_TW_H_
#define _MSG_0X00_KEEPALIVE_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class KeepAlive : public BaseMessage
{
public:
	KeepAlive();
	KeepAlive(int32_t _keepAliveId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getKeepAliveId() const;

	void setKeepAliveId(int32_t _val);


private:
	int32_t _pf_keepAliveId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X00_KEEPALIVE_TW_H_