#ifndef _MSG_0X05_ENTITYEQUIPMENT_STC_H_
#define _MSG_0X05_ENTITYEQUIPMENT_STC_H_

#include "mcprotocol_base.h"
#include "slotdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityEquipment : public BaseMessage
{
public:
	EntityEquipment();
	EntityEquipment(int32_t _entityId, int16_t _slot, SlotData _item);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int16_t getSlot() const;
	SlotData getItem() const;

	void setEntityId(int32_t _val);
	void setSlot(int16_t _val);
	void setItem(SlotData _val);


private:
	int32_t _pf_entityId;
	int16_t _pf_slot;
	SlotData _pf_item;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X05_ENTITYEQUIPMENT_STC_H_