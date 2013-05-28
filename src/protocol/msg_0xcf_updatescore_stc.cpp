#include "msg_0xcf_updatescore_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

UpdateScore::UpdateScore()
{
	_pf_packetId = static_cast<int8_t>(0xCF);
	_pf_initialized = false;
}

UpdateScore::UpdateScore(const String16& _itemName, int8_t _update_remove, const String16& _scoreName, int32_t _value)
	:	_pf_itemName(_itemName)
	,	_pf_update_remove(_update_remove)
	,	_pf_scoreName(_scoreName)
	,	_pf_value(_value)
{
	_pf_packetId = static_cast<int8_t>(0xCF);
	_pf_initialized = true;
}


size_t UpdateScore::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_itemName);
	_offset = WriteInt8(_dst, _offset, _pf_update_remove);
	_offset = WriteString16(_dst, _offset, _pf_scoreName);
	_offset = WriteInt32(_dst, _offset, _pf_value);


	return _offset;
}

size_t UpdateScore::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_itemName);
	_offset = ReadInt8(_src, _offset, _pf_update_remove);
	_offset = ReadString16(_src, _offset, _pf_scoreName);
	_offset = ReadInt32(_src, _offset, _pf_value);
	_pf_initialized = true;
	return _offset;
}

const String16& UpdateScore::getItemName() const { return _pf_itemName; }
int8_t UpdateScore::getUpdate_remove() const { return _pf_update_remove; }
const String16& UpdateScore::getScoreName() const { return _pf_scoreName; }
int32_t UpdateScore::getValue() const { return _pf_value; }

void UpdateScore::setItemName(const String16& _val) { _pf_itemName = _val; }
void UpdateScore::setUpdate_remove(int8_t _val) { _pf_update_remove = _val; }
void UpdateScore::setScoreName(const String16& _val) { _pf_scoreName = _val; }
void UpdateScore::setValue(int32_t _val) { _pf_value = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
