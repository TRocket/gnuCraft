#ifndef _MSG_0X19_SPAWNPAINTING_STC_H_
#define _MSG_0X19_SPAWNPAINTING_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SpawnPainting : public BaseMessage
{
public:
	SpawnPainting();
	SpawnPainting(int32_t _entityId, const String16& _title, int32_t _x, int32_t _y, int32_t _z, int32_t _direction);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	const String16& getTitle() const;
	int32_t getX() const;
	int32_t getY() const;
	int32_t getZ() const;
	int32_t getDirection() const;

	void setEntityId(int32_t _val);
	void setTitle(const String16& _val);
	void setX(int32_t _val);
	void setY(int32_t _val);
	void setZ(int32_t _val);
	void setDirection(int32_t _val);


private:
	int32_t _pf_entityId;
	String16 _pf_title;
	int32_t _pf_x;
	int32_t _pf_y;
	int32_t _pf_z;
	int32_t _pf_direction;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X19_SPAWNPAINTING_STC_H_