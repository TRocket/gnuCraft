#ifndef _MSG_0X1F_ENTITYRELATIVEMOVE_STC_H_
#define _MSG_0X1F_ENTITYRELATIVEMOVE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityRelativeMove : public BaseMessage
{
public:
	EntityRelativeMove();
	EntityRelativeMove(int32_t _entityId, int8_t _dx, int8_t _dy, int8_t _dz);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int8_t getDx() const;
	int8_t getDy() const;
	int8_t getDz() const;

	void setEntityId(int32_t _val);
	void setDx(int8_t _val);
	void setDy(int8_t _val);
	void setDz(int8_t _val);


private:
	int32_t _pf_entityId;
	int8_t _pf_dx;
	int8_t _pf_dy;
	int8_t _pf_dz;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X1F_ENTITYRELATIVEMOVE_STC_H_