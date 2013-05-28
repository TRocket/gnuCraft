#ifndef _MSG_0X29_ENTITYEFFECT_STC_H_
#define _MSG_0X29_ENTITYEFFECT_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityEffect : public BaseMessage
{
public:
	EntityEffect();
	EntityEffect(int32_t _entityId, int32_t _effectId, int8_t _amplifier, int16_t _duration);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int32_t getEffectId() const;
	int8_t getAmplifier() const;
	int16_t getDuration() const;

	void setEntityId(int32_t _val);
	void setEffectId(int32_t _val);
	void setAmplifier(int8_t _val);
	void setDuration(int16_t _val);


private:
	int32_t _pf_entityId;
	int32_t _pf_effectId;
	int8_t _pf_amplifier;
	int16_t _pf_duration;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X29_ENTITYEFFECT_STC_H_