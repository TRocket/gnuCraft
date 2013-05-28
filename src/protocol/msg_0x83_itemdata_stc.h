#ifndef _MSG_0X83_ITEMDATA_STC_H_
#define _MSG_0X83_ITEMDATA_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ItemData : public BaseMessage
{
public:
	ItemData();
	ItemData(int16_t _itemType, int16_t _itemId, int16_t _textLength, const ByteArray& _text);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int16_t getItemType() const;
	int16_t getItemId() const;
	int16_t getTextLength() const;
	const ByteArray& getText() const;

	void setItemType(int16_t _val);
	void setItemId(int16_t _val);
	void setTextLength(int16_t _val);
	void setText(const ByteArray& _val);


private:
	int16_t _pf_itemType;
	int16_t _pf_itemId;
	int16_t _pf_textLength;
	ByteArray _pf_text;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X83_ITEMDATA_STC_H_