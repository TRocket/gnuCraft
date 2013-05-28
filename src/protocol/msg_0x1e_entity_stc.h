#ifndef _MSG_0X1E_ENTITY_STC_H_
#define _MSG_0X1E_ENTITY_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Entity : public BaseMessage
{
public:
	Entity();
	Entity(int32_t _entityId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;

	void setEntityId(int32_t _val);


private:
	int32_t _pf_entityId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X1E_ENTITY_STC_H_