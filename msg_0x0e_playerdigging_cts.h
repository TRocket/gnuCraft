#ifndef _MSG_0X0E_PLAYERDIGGING_CTS_H_
#define _MSG_0X0E_PLAYERDIGGING_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class PlayerDigging : public BaseMessage
{
public:
	PlayerDigging();
	PlayerDigging(int8_t _status, int32_t _x, int8_t _y, int32_t _z, int8_t _face);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getStatus() const;
	int32_t getX() const;
	int8_t getY() const;
	int32_t getZ() const;
	int8_t getFace() const;

	void setStatus(int8_t _val);
	void setX(int32_t _val);
	void setY(int8_t _val);
	void setZ(int32_t _val);
	void setFace(int8_t _val);


private:
	int8_t _pf_status;
	int32_t _pf_x;
	int8_t _pf_y;
	int32_t _pf_z;
	int8_t _pf_face;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X0E_PLAYERDIGGING_CTS_H_