#include "msg_0x6b_creativeinventoryaction_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

CreativeInventoryAction::CreativeInventoryAction()
{
	_pf_packetId = static_cast<int8_t>(0x6B);
	_pf_initialized = false;
}

CreativeInventoryAction::CreativeInventoryAction(int16_t _slot, SlotData _clickedItem)
	:	_pf_slot(_slot)
	,	_pf_clickedItem(_clickedItem)
{
	_pf_packetId = static_cast<int8_t>(0x6B);
	_pf_initialized = true;
}


size_t CreativeInventoryAction::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt16(_dst, _offset, _pf_slot);
	//_offset = WriteSlotData(_dst, _offset, _pf_clickedItem);
	_offset = _pf_clickedItem.serialize(_dst, _offset);

	return _offset;
}

size_t CreativeInventoryAction::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt16(_src, _offset, _pf_slot);
	//_offset = ReadSlotData(_src, _offset, _pf_clickedItem);
	_offset = _pf_clickedItem.deserialize(_src, _offset);
	_pf_initialized = true;
	return _offset;
}

int16_t CreativeInventoryAction::getSlot() const { return _pf_slot; }
SlotData CreativeInventoryAction::getClickedItem() const { return _pf_clickedItem; }

void CreativeInventoryAction::setSlot(int16_t _val) { _pf_slot = _val; }
void CreativeInventoryAction::setClickedItem(SlotData _val) { _pf_clickedItem = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
