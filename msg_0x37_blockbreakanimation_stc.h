#ifndef _MSG_0X37_BLOCKBREAKANIMATION_STC_H_
#define _MSG_0X37_BLOCKBREAKANIMATION_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class BlockBreakAnimation : public BaseMessage
{
public:
	BlockBreakAnimation();
	BlockBreakAnimation(int32_t _EntityId, int32_t _x, int32_t _y, int32_t _z, int8_t _destroyStage);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int32_t getX() const;
	int32_t getY() const;
	int32_t getZ() const;
	int8_t getDestroyStage() const;

	void setEntityId(int32_t _val);
	void setX(int32_t _val);
	void setY(int32_t _val);
	void setZ(int32_t _val);
	void setDestroyStage(int8_t _val);


private:
	int32_t _pf_EntityId;
	int32_t _pf_x;
	int32_t _pf_y;
	int32_t _pf_z;
	int8_t _pf_destroyStage;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X37_BLOCKBREAKANIMATION_STC_H_