#ifndef _MSG_0X1A_SPAWNEXPERIENCEORB_STC_H_
#define _MSG_0X1A_SPAWNEXPERIENCEORB_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SpawnExperienceOrb : public BaseMessage
{
public:
	SpawnExperienceOrb();
	SpawnExperienceOrb(int32_t _entityId, int32_t _x, int32_t _y, int32_t _z, int16_t _count);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int32_t getX() const;
	int32_t getY() const;
	int32_t getZ() const;
	int16_t getCount() const;

	void setEntityId(int32_t _val);
	void setX(int32_t _val);
	void setY(int32_t _val);
	void setZ(int32_t _val);
	void setCount(int16_t _val);


private:
	int32_t _pf_entityId;
	int32_t _pf_x;
	int32_t _pf_y;
	int32_t _pf_z;
	int16_t _pf_count;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X1A_SPAWNEXPERIENCEORB_STC_H_