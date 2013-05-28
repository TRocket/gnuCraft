#ifndef _MSG_0X0B_PLAYERPOSITION_CTS_H_
#define _MSG_0X0B_PLAYERPOSITION_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class PlayerPosition : public BaseMessage
{
public:
	PlayerPosition();
	PlayerPosition(double _x, double _y, double _stance, double _z, bool _onGround);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	double getX() const;
	double getY() const;
	double getStance() const;
	double getZ() const;
	bool getOnGround() const;

	void setX(double _val);
	void setY(double _val);
	void setStance(double _val);
	void setZ(double _val);
	void setOnGround(bool _val);


private:
	double _pf_x;
	double _pf_y;
	double _pf_stance;
	double _pf_z;
	bool _pf_onGround;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X0B_PLAYERPOSITION_CTS_H_