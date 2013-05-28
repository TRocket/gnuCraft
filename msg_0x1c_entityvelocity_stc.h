#ifndef _MSG_0X1C_ENTITYVELOCITY_STC_H_
#define _MSG_0X1C_ENTITYVELOCITY_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityVelocity : public BaseMessage
{
public:
	EntityVelocity();
	EntityVelocity(int32_t _entityId, int16_t _xVelocity, int16_t _yVeclosity, int16_t _zVelocity);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int16_t getXVelocity() const;
	int16_t getYVeclosity() const;
	int16_t getZVelocity() const;

	void setEntityId(int32_t _val);
	void setXVelocity(int16_t _val);
	void setYVeclosity(int16_t _val);
	void setZVelocity(int16_t _val);


private:
	int32_t _pf_entityId;
	int16_t _pf_xVelocity;
	int16_t _pf_yVeclosity;
	int16_t _pf_zVelocity;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X1C_ENTITYVELOCITY_STC_H_