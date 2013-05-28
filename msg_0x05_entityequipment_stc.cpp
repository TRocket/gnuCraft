#include "msg_0x05_entityequipment_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityEquipment::EntityEquipment()
{
	_pf_packetId = static_cast<int8_t>(0x05);
	_pf_initialized = false;
}

EntityEquipment::EntityEquipment(int32_t _entityId, int16_t _slot, SlotData _item)
	:	_pf_entityId(_entityId)
	,	_pf_slot(_slot)
	,	_pf_item(_item)
{
	_pf_packetId = static_cast<int8_t>(0x05);
	_pf_initialized = true;
}


size_t EntityEquipment::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt16(_dst, _offset, _pf_slot);
	//_offset = WriteSlotData(_dst, _offset, _pf_item);
	_offset = _pf_item.serialize(_dst, _offset);

	return _offset;
}

size_t EntityEquipment::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt16(_src, _offset, _pf_slot);
	//_offset = ReadSlotData(_src, _offset, _pf_item);
	_offset = _pf_item.deserialize(_src, _offset);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityEquipment::getEntityId() const { return _pf_entityId; }
int16_t EntityEquipment::getSlot() const { return _pf_slot; }
SlotData EntityEquipment::getItem() const { return _pf_item; }

void EntityEquipment::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityEquipment::setSlot(int16_t _val) { _pf_slot = _val; }
void EntityEquipment::setItem(SlotData _val) { _pf_item = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
