#include "msg_0x6c_encnahtitem_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EncnahtItem::EncnahtItem()
{
	_pf_packetId = static_cast<int8_t>(0x6C);
	_pf_initialized = false;
}

EncnahtItem::EncnahtItem(int8_t _windowId, int8_t _enchantment)
	:	_pf_windowId(_windowId)
	,	_pf_enchantment(_enchantment)
{
	_pf_packetId = static_cast<int8_t>(0x6C);
	_pf_initialized = true;
}


size_t EncnahtItem::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_windowId);
	_offset = WriteInt8(_dst, _offset, _pf_enchantment);


	return _offset;
}

size_t EncnahtItem::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_windowId);
	_offset = ReadInt8(_src, _offset, _pf_enchantment);
	_pf_initialized = true;
	return _offset;
}

int8_t EncnahtItem::getWindowId() const { return _pf_windowId; }
int8_t EncnahtItem::getEnchantment() const { return _pf_enchantment; }

void EncnahtItem::setWindowId(int8_t _val) { _pf_windowId = _val; }
void EncnahtItem::setEnchantment(int8_t _val) { _pf_enchantment = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
