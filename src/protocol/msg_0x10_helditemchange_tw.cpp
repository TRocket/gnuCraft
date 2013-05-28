#include "msg_0x10_helditemchange_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

HeldItemChange::HeldItemChange()
{
	_pf_packetId = static_cast<int8_t>(0x10);
	_pf_initialized = false;
}

HeldItemChange::HeldItemChange(int16_t _slotId)
	:	_pf_slotId(_slotId)
{
	_pf_packetId = static_cast<int8_t>(0x10);
	_pf_initialized = true;
}


size_t HeldItemChange::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt16(_dst, _offset, _pf_slotId);


	return _offset;
}

size_t HeldItemChange::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt16(_src, _offset, _pf_slotId);
	_pf_initialized = true;
	return _offset;
}

int16_t HeldItemChange::getSlotId() const { return _pf_slotId; }

void HeldItemChange::setSlotId(int16_t _val) { _pf_slotId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
