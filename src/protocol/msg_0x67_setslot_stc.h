#ifndef _MSG_0X67_SETSLOT_STC_H_
#define _MSG_0X67_SETSLOT_STC_H_

#include "mcprotocol_base.h"
#include "slotdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SetSlot : public BaseMessage
{
public:
	SetSlot();
	SetSlot(int8_t _windowId, int16_t _slotNum);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getWindowId() const;
	int16_t getSlotNum() const;

	void setWindowId(int8_t _val);
	void setSlotNum(int16_t _val);


private:
	int8_t _pf_windowId;
	int16_t _pf_slotNum;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X67_SETSLOT_STC_H_