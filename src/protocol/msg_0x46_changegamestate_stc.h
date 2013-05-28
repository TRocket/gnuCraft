#ifndef _MSG_0X46_CHANGEGAMESTATE_STC_H_
#define _MSG_0X46_CHANGEGAMESTATE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ChangeGameState : public BaseMessage
{
public:
	ChangeGameState();
	ChangeGameState(int8_t _reason, int8_t _gameMode);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getReason() const;
	int8_t getGameMode() const;

	void setReason(int8_t _val);
	void setGameMode(int8_t _val);


private:
	int8_t _pf_reason;
	int8_t _pf_gameMode;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X46_CHANGEGAMESTATE_STC_H_