#ifndef _MSG_0XCD_CLIENTSTATUSES_CTS_H_
#define _MSG_0XCD_CLIENTSTATUSES_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ClientStatuses : public BaseMessage
{
public:
	ClientStatuses();
	ClientStatuses(int8_t _payload);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getPayload() const;

	void setPayload(int8_t _val);


private:
	int8_t _pf_payload;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XCD_CLIENTSTATUSES_CTS_H_