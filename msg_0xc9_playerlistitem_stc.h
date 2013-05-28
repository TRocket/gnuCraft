#ifndef _MSG_0XC9_PLAYERLISTITEM_STC_H_
#define _MSG_0XC9_PLAYERLISTITEM_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class PlayerListItem : public BaseMessage
{
public:
	PlayerListItem();
	PlayerListItem(const String16& _playerName, bool _online, int16_t _ping);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getPlayerName() const;
	bool getOnline() const;
	int16_t getPing() const;

	void setPlayerName(const String16& _val);
	void setOnline(bool _val);
	void setPing(int16_t _val);


private:
	String16 _pf_playerName;
	bool _pf_online;
	int16_t _pf_ping;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XC9_PLAYERLISTITEM_STC_H_