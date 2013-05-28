#ifndef _MSG_0X18_SPAWNMOB_STC_H_
#define _MSG_0X18_SPAWNMOB_STC_H_

#include "mcprotocol_base.h"
#include "metadata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SpawnMob : public BaseMessage
{
public:
	SpawnMob();
	SpawnMob(int32_t _entityId, int8_t _type, int32_t _x, int32_t _y, int32_t _z, int8_t _pitch, int8_t _headPitch, int8_t _yaw, int16_t _xVelocity, int16_t _yVelocity, int16_t _zVelocity);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int8_t getType() const;
	int32_t getX() const;
	int32_t getY() const;
	int32_t getZ() const;
	int8_t getPitch() const;
	int8_t getHeadPitch() const;
	int8_t getYaw() const;
	int16_t getXVelocity() const;
	int16_t getYVelocity() const;
	int16_t getZVelocity() const;

	void setEntityId(int32_t _val);
	void setType(int8_t _val);
	void setX(int32_t _val);
	void setY(int32_t _val);
	void setZ(int32_t _val);
	void setPitch(int8_t _val);
	void setHeadPitch(int8_t _val);
	void setYaw(int8_t _val);
	void setXVelocity(int16_t _val);
	void setYVelocity(int16_t _val);
	void setZVelocity(int16_t _val);


private:
	int32_t _pf_entityId;
	int8_t _pf_type;
	int32_t _pf_x;
	int32_t _pf_y;
	int32_t _pf_z;
	int8_t _pf_pitch;
	int8_t _pf_headPitch;
	int8_t _pf_yaw;
	int16_t _pf_xVelocity;
	int16_t _pf_yVelocity;
	int16_t _pf_zVelocity;
	Metadata _pf_metadata;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X18_SPAWNMOB_STC_H_