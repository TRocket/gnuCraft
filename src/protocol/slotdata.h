#ifndef _SLOTDATA_H_
#define _SLOTDATA_H_

#include "mcprotocol_base.h"


namespace MC
{
namespace Protocol
{
namespace Msg
{

// Пока что этот класс будет считаться сообщением, пока я не придумал, куда его деть.
class SlotData : public BaseMessage
{
public:
	SlotData();
	SlotData(int16_t _itemId, int8_t _itemCount, int16_t _itemDamage, int16_t _nbtDataLen);

	size_t serialize(Buffer& _src, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int16_t getItemId() const;
	int8_t getItemCount() const;
	int16_t getItemDamage() const;
	int16_t getNbtDataLen() const;

	void setItemId(int16_t _val);
	void setItemCount(int8_t _val);
	void setItemDamage(int16_t _val);
	void setNbtDataLen(int16_t _val);


private:
	int16_t _pf_itemId;
	int8_t _pf_itemCount;
	int16_t _pf_itemDamage;
	int16_t _pf_nbtDataLen;
	
	ByteArray _pf_nbtData;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _SLOTDATA_H_