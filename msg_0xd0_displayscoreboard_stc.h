#ifndef _MSG_0XD0_DISPLAYSCOREBOARD_STC_H_
#define _MSG_0XD0_DISPLAYSCOREBOARD_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class DisplayScoreboard : public BaseMessage
{
public:
	DisplayScoreboard();
	DisplayScoreboard(int8_t _position, const String16& _scoreName);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getPosition() const;
	const String16& getScoreName() const;

	void setPosition(int8_t _val);
	void setScoreName(const String16& _val);


private:
	int8_t _pf_position;
	String16 _pf_scoreName;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XD0_DISPLAYSCOREBOARD_STC_H_