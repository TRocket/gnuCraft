#ifndef _MSG_0X21_ENTITYLOOKANDRELATIVEMOVE_STC_H_
#define _MSG_0X21_ENTITYLOOKANDRELATIVEMOVE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityLookAndRelativeMove : public BaseMessage
{
public:
	EntityLookAndRelativeMove();
	EntityLookAndRelativeMove(int32_t _entityId, int8_t _dx, int8_t _dy, int8_t _dz, int8_t _yaw, int8_t _pitch);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int8_t getDx() const;
	int8_t getDy() const;
	int8_t getDz() const;
	int8_t getYaw() const;
	int8_t getPitch() const;

	void setEntityId(int32_t _val);
	void setDx(int8_t _val);
	void setDy(int8_t _val);
	void setDz(int8_t _val);
	void setYaw(int8_t _val);
	void setPitch(int8_t _val);


private:
	int32_t _pf_entityId;
	int8_t _pf_dx;
	int8_t _pf_dy;
	int8_t _pf_dz;
	int8_t _pf_yaw;
	int8_t _pf_pitch;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X21_ENTITYLOOKANDRELATIVEMOVE_STC_H_