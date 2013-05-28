#ifndef _MSG_0X12_ANIMATION_TW_H_
#define _MSG_0X12_ANIMATION_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Animation : public BaseMessage
{
public:
	Animation();
	Animation(int32_t _playerId, int8_t _animId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getPlayerId() const;
	int8_t getAnimId() const;

	void setPlayerId(int32_t _val);
	void setAnimId(int8_t _val);


private:
	int32_t _pf_playerId;
	int8_t _pf_animId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X12_ANIMATION_TW_H_