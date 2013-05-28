#ifndef _MSG_0X6C_ENCNAHTITEM_STC_H_
#define _MSG_0X6C_ENCNAHTITEM_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EncnahtItem : public BaseMessage
{
public:
	EncnahtItem();
	EncnahtItem(int8_t _windowId, int8_t _enchantment);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getWindowId() const;
	int8_t getEnchantment() const;

	void setWindowId(int8_t _val);
	void setEnchantment(int8_t _val);


private:
	int8_t _pf_windowId;
	int8_t _pf_enchantment;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X6C_ENCNAHTITEM_STC_H_