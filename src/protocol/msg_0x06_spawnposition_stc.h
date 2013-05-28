#ifndef _MSG_0X06_SPAWNPOSITION_STC_H_
#define _MSG_0X06_SPAWNPOSITION_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SpawnPosition : public BaseMessage
{
public:
	SpawnPosition();
	SpawnPosition(int32_t _x, int32_t _y, int32_t _z);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getX() const;
	int32_t getY() const;
	int32_t getZ() const;

	void setX(int32_t _val);
	void setY(int32_t _val);
	void setZ(int32_t _val);


private:
	int32_t _pf_x;
	int32_t _pf_y;
	int32_t _pf_z;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X06_SPAWNPOSITION_STC_H_