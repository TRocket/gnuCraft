#ifndef _MSG_0X0A_PLAYER_CTS_H_
#define _MSG_0X0A_PLAYER_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Player : public BaseMessage
{
public:
	Player();
	Player(bool _onGround);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	bool getOnGround() const;

	void setOnGround(bool _val);


private:
	bool _pf_onGround;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X0A_PLAYER_CTS_H_