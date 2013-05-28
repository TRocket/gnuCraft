#include "slotdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SlotData::SlotData()
{
	//_pf_packetId = static_cast<int8_t>(0xzz);
	_pf_initialized = false;
}

SlotData::SlotData(int16_t _itemId, int8_t _itemCount, int16_t _itemDamage, int16_t _nbtDataLen)
	:	_pf_itemId(_itemId)
	,	_pf_itemCount(_itemCount)
	,	_pf_itemDamage(_itemDamage)
	,	_pf_nbtDataLen(_nbtDataLen)
{
	//_pf_packetId = static_cast<int8_t>(0xzz);
	_pf_initialized = true;
}


size_t SlotData::serialize(Buffer& _src, size_t _offset)
{
	//_pm_checkInit();
	//_dst.clear();

	//_pm_serializeInt8(_pf_packetId, _dst);
	//_pm_serializeInt16(_pf_itemId, _dst);
	//_pm_serializeInt8(_pf_itemCount, _dst);
	//_pm_serializeInt16(_pf_itemDamage, _dst);
	//_pm_serializeInt16(_pf_nbtDataLen, _dst);

	std::cout << __FUNCTION__ << " NYI!" << std::endl;
	throw "NYI";
}

size_t SlotData::deserialize(const Buffer& _src, size_t _offset)
{
	//_pm_checkPacketId(_src);

	_offset = ReadInt(_src, _offset, _pf_itemId);
	
	if(_pf_itemId != -1)
	{
		_offset = ReadInt8(_src, _offset, _pf_itemCount);
		_offset = ReadInt16(_src, _offset, _pf_itemDamage);
		_offset = ReadInt16(_src, _offset, _pf_nbtDataLen);
		
		if(_pf_nbtDataLen != -1)
		{
			_offset = ReadByteArray(_src, _offset, _pf_nbtDataLen, _pf_nbtData);
			// Дальше должно быть разжатие, но потом
		}
	}
	
	return _offset;
	//_pf_initialized = true;
}

int16_t SlotData::getItemId() const { return _pf_itemId; }
int8_t SlotData::getItemCount() const { return _pf_itemCount; }
int16_t SlotData::getItemDamage() const { return _pf_itemDamage; }
int16_t SlotData::getNbtDataLen() const { return _pf_nbtDataLen; }

void SlotData::setItemId(int16_t _val) { _pf_itemId = _val; }
void SlotData::setItemCount(int8_t _val) { _pf_itemCount = _val; }
void SlotData::setItemDamage(int16_t _val) { _pf_itemDamage = _val; }
void SlotData::setNbtDataLen(int16_t _val) { _pf_nbtDataLen = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
