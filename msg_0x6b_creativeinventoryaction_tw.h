#ifndef _MSG_0X6B_CREATIVEINVENTORYACTION_TW_H_
#define _MSG_0X6B_CREATIVEINVENTORYACTION_TW_H_

#include "mcprotocol_base.h"
#include "slotdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class CreativeInventoryAction : public BaseMessage
{
public:
	CreativeInventoryAction();
	CreativeInventoryAction(int16_t _slot, SlotData _clickedItem);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int16_t getSlot() const;
	SlotData getClickedItem() const;

	void setSlot(int16_t _val);
	void setClickedItem(SlotData _val);


private:
	int16_t _pf_slot;
	SlotData _pf_clickedItem;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X6B_CREATIVEINVENTORYACTION_TW_H_