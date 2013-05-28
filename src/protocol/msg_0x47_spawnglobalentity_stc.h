#ifndef _MSG_0X47_SPAWNGLOBALENTITY_STC_H_
#define _MSG_0X47_SPAWNGLOBALENTITY_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SpawnGlobalEntity : public BaseMessage
{
public:
	SpawnGlobalEntity();
	SpawnGlobalEntity(int32_t _entityId, int8_t _type, int32_t _x, int32_t _y, int32_t _z);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int8_t getType() const;
	int32_t getX() const;
	int32_t getY() const;
	int32_t getZ() const;

	void setEntityId(int32_t _val);
	void setType(int8_t _val);
	void setX(int32_t _val);
	void setY(int32_t _val);
	void setZ(int32_t _val);


private:
	int32_t _pf_entityId;
	int8_t _pf_type;
	int32_t _pf_x;
	int32_t _pf_y;
	int32_t _pf_z;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X47_SPAWNGLOBALENTITY_STC_H_