#ifndef _MSG_0X0C_PLAYERLOOK_CTS_H_
#define _MSG_0X0C_PLAYERLOOK_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class PlayerLook : public BaseMessage
{
public:
	PlayerLook();
	PlayerLook(float _yaw, float _pitch, bool _onGround);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	float getYaw() const;
	float getPitch() const;
	bool getOnGround() const;

	void setYaw(float _val);
	void setPitch(float _val);
	void setOnGround(bool _val);


private:
	float _pf_yaw;
	float _pf_pitch;
	bool _pf_onGround;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X0C_PLAYERLOOK_CTS_H_