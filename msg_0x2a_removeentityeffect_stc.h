#ifndef _MSG_0X2A_REMOVEENTITYEFFECT_STC_H_
#define _MSG_0X2A_REMOVEENTITYEFFECT_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class RemoveEntityEffect : public BaseMessage
{
public:
	RemoveEntityEffect();
	RemoveEntityEffect(int32_t _entityId, int32_t _effectId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int32_t getEffectId() const;

	void setEntityId(int32_t _val);
	void setEffectId(int32_t _val);


private:
	int32_t _pf_entityId;
	int32_t _pf_effectId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X2A_REMOVEENTITYEFFECT_STC_H_