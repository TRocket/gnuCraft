#ifndef _MSG_0X22_ENTITYTELEPORT_STC_H_
#define _MSG_0X22_ENTITYTELEPORT_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityTeleport : public BaseMessage
{
public:
	EntityTeleport();
	EntityTeleport(int32_t _entityId, int32_t _x, int32_t _y, int32_t _z, int8_t _yaw, int8_t _pitch);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int32_t getX() const;
	int32_t getY() const;
	int32_t getZ() const;
	int8_t getYaw() const;
	int8_t getPitch() const;

	void setEntityId(int32_t _val);
	void setX(int32_t _val);
	void setY(int32_t _val);
	void setZ(int32_t _val);
	void setYaw(int8_t _val);
	void setPitch(int8_t _val);


private:
	int32_t _pf_entityId;
	int32_t _pf_x;
	int32_t _pf_y;
	int32_t _pf_z;
	int8_t _pf_yaw;
	int8_t _pf_pitch;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X22_ENTITYTELEPORT_STC_H_