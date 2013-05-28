#ifndef _MSG_0X13_ENTITYACTION_CTS_H_
#define _MSG_0X13_ENTITYACTION_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityAction : public BaseMessage
{
public:
	EntityAction();
	EntityAction(int32_t _entityId, int8_t _actionId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int8_t getActionId() const;

	void setEntityId(int32_t _val);
	void setActionId(int8_t _val);


private:
	int32_t _pf_entityId;
	int8_t _pf_actionId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X13_ENTITYACTION_CTS_H_