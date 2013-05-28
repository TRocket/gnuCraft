#ifndef _MSG_0X0D_PLAYERPOSITIONANDLOOK_TW_H_
#define _MSG_0X0D_PLAYERPOSITIONANDLOOK_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class PlayerPositionAndLook : public BaseMessage
{
public:
	PlayerPositionAndLook();
	PlayerPositionAndLook(double _x, double _y, double _stance, double _z, float _yaw, float _pitch, bool _onGround);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	double getX() const;
	double getY() const;
	double getStance() const;
	double getZ() const;
	float getYaw() const;
	float getPitch() const;
	bool getOnGround() const;

	void setX(double _val);
	void setY(double _val);
	void setStance(double _val);
	void setZ(double _val);
	void setYaw(float _val);
	void setPitch(float _val);
	void setOnGround(bool _val);


private:
	double _pf_x;
	double _pf_y;
	double _pf_stance;
	double _pf_z;
	float _pf_yaw;
	float _pf_pitch;
	bool _pf_onGround;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X0D_PLAYERPOSITIONANDLOOK_TW_H_