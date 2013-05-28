#ifndef _MSG_0XC8_INCREMENTSTATISTIC_STC_H_
#define _MSG_0XC8_INCREMENTSTATISTIC_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class IncrementStatistic : public BaseMessage
{
public:
	IncrementStatistic();
	IncrementStatistic(int32_t _statisticId, int8_t _amount);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getStatisticId() const;
	int8_t getAmount() const;

	void setStatisticId(int32_t _val);
	void setAmount(int8_t _val);


private:
	int32_t _pf_statisticId;
	int8_t _pf_amount;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XC8_INCREMENTSTATISTIC_STC_H_