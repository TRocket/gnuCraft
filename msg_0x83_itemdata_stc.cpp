#include "msg_0x83_itemdata_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ItemData::ItemData()
{
	_pf_packetId = static_cast<int8_t>(0x83);
	_pf_initialized = false;
}

ItemData::ItemData(int16_t _itemType, int16_t _itemId, int16_t _textLength, const ByteArray& _text)
	:	_pf_itemType(_itemType)
	,	_pf_itemId(_itemId)
	,	_pf_textLength(_textLength)
	,	_pf_text(_text)
{
	_pf_packetId = static_cast<int8_t>(0x83);
	_pf_initialized = true;
}


size_t ItemData::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt16(_dst, _offset, _pf_itemType);
	_offset = WriteInt16(_dst, _offset, _pf_itemId);
	_offset = WriteInt16(_dst, _offset, _pf_textLength);
	_offset = WriteByteArray(_dst, _offset, _pf_text);


	return _offset;
}

size_t ItemData::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt16(_src, _offset, _pf_itemType);
	_offset = ReadInt16(_src, _offset, _pf_itemId);
	_offset = ReadInt16(_src, _offset, _pf_textLength);
	_offset = ReadByteArray(_src, _offset, _pf_textLength, _pf_text);
	_pf_initialized = true;
	return _offset;
}

int16_t ItemData::getItemType() const { return _pf_itemType; }
int16_t ItemData::getItemId() const { return _pf_itemId; }
int16_t ItemData::getTextLength() const { return _pf_textLength; }
const ByteArray& ItemData::getText() const { return _pf_text; }

void ItemData::setItemType(int16_t _val) { _pf_itemType = _val; }
void ItemData::setItemId(int16_t _val) { _pf_itemId = _val; }
void ItemData::setTextLength(int16_t _val) { _pf_textLength = _val; }
void ItemData::setText(const ByteArray& _val) { _pf_text = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
