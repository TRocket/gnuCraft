#ifndef _MSG_0X26_ENTITYSTATUS_STC_H_
#define _MSG_0X26_ENTITYSTATUS_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityStatus : public BaseMessage
{
public:
	EntityStatus();
	EntityStatus(int32_t _entityId, int8_t _entityStatus);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int8_t getEntityStatus() const;

	void setEntityId(int32_t _val);
	void setEntityStatus(int8_t _val);


private:
	int32_t _pf_entityId;
	int8_t _pf_entityStatus;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X26_ENTITYSTATUS_STC_H_