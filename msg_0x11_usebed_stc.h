#ifndef _MSG_0X11_USEBED_STC_H_
#define _MSG_0X11_USEBED_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class UseBed : public BaseMessage
{
public:
	UseBed();
	UseBed(int32_t _entityId, int8_t _unknown, int32_t _x, int8_t _y, int32_t _z);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int8_t getUnknown() const;
	int32_t getX() const;
	int8_t getY() const;
	int32_t getZ() const;

	void setEntityId(int32_t _val);
	void setUnknown(int8_t _val);
	void setX(int32_t _val);
	void setY(int8_t _val);
	void setZ(int32_t _val);


private:
	int32_t _pf_entityId;
	int8_t _pf_unknown;
	int32_t _pf_x;
	int8_t _pf_y;
	int32_t _pf_z;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X11_USEBED_STC_H_