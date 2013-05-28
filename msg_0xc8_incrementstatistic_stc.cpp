#include "msg_0xc8_incrementstatistic_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

IncrementStatistic::IncrementStatistic()
{
	_pf_packetId = static_cast<int8_t>(0xC8);
	_pf_initialized = false;
}

IncrementStatistic::IncrementStatistic(int32_t _statisticId, int8_t _amount)
	:	_pf_statisticId(_statisticId)
	,	_pf_amount(_amount)
{
	_pf_packetId = static_cast<int8_t>(0xC8);
	_pf_initialized = true;
}


size_t IncrementStatistic::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_statisticId);
	_offset = WriteInt8(_dst, _offset, _pf_amount);


	return _offset;
}

size_t IncrementStatistic::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_statisticId);
	_offset = ReadInt8(_src, _offset, _pf_amount);
	_pf_initialized = true;
	return _offset;
}

int32_t IncrementStatistic::getStatisticId() const { return _pf_statisticId; }
int8_t IncrementStatistic::getAmount() const { return _pf_amount; }

void IncrementStatistic::setStatisticId(int32_t _val) { _pf_statisticId = _val; }
void IncrementStatistic::setAmount(int8_t _val) { _pf_amount = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
