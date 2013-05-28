#ifndef _MSG_0X10_HELDITEMCHANGE_TW_H_
#define _MSG_0X10_HELDITEMCHANGE_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class HeldItemChange : public BaseMessage
{
public:
	HeldItemChange();
	HeldItemChange(int16_t _slotId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int16_t getSlotId() const;

	void setSlotId(int16_t _val);


private:
	int16_t _pf_slotId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X10_HELDITEMCHANGE_TW_H_