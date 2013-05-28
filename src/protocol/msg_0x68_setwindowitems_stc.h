#ifndef _MSG_0X68_SETWINDOWITEMS_STC_H_
#define _MSG_0X68_SETWINDOWITEMS_STC_H_

#include "mcprotocol_base.h"
#include "slotdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SetWindowItems : public BaseMessage
{
public:
	SetWindowItems();
	SetWindowItems(int8_t _windowId, int16_t _slotsCount);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getWindowId() const;
	int16_t getSlotsCount() const;

	void setWindowId(int8_t _val);
	void setSlotsCount(int16_t _val);


private:
	int8_t _pf_windowId;
	int16_t _pf_slotsCount;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X68_SETWINDOWITEMS_STC_H_