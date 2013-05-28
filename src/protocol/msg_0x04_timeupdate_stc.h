#ifndef _MSG_0X04_TIMEUPDATE_STC_H_
#define _MSG_0X04_TIMEUPDATE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class TimeUpdate : public BaseMessage
{
public:
	TimeUpdate();
	TimeUpdate(int64_t _worldAge, int64_t _timeOfDay);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int64_t getWorldAge() const;
	int64_t getTimeOfDay() const;

	void setWorldAge(int64_t _val);
	void setTimeOfDay(int64_t _val);


private:
	int64_t _pf_worldAge;
	int64_t _pf_timeOfDay;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X04_TIMEUPDATE_STC_H_