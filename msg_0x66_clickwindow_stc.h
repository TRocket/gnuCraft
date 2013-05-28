#ifndef _MSG_0X66_CLICKWINDOW_STC_H_
#define _MSG_0X66_CLICKWINDOW_STC_H_

#include "mcprotocol_base.h"
#include "slotdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ClickWindow : public BaseMessage
{
public:
	ClickWindow();
	ClickWindow(int8_t _windowId, int16_t _slot, int8_t _button, int16_t _actionNumber, int8_t _mode, SlotData _clickedItem);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getWindowId() const;
	int16_t getSlot() const;
	int8_t getButton() const;
	int16_t getActionNumber() const;
	int8_t getMode() const;
	SlotData getClickedItem() const;

	void setWindowId(int8_t _val);
	void setSlot(int16_t _val);
	void setButton(int8_t _val);
	void setActionNumber(int16_t _val);
	void setMode(int8_t _val);
	void setClickedItem(SlotData _val);


private:
	int8_t _pf_windowId;
	int16_t _pf_slot;
	int8_t _pf_button;
	int16_t _pf_actionNumber;
	int8_t _pf_mode;
	SlotData _pf_clickedItem;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X66_CLICKWINDOW_STC_H_