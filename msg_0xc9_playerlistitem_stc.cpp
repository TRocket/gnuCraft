#include "msg_0xc9_playerlistitem_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

PlayerListItem::PlayerListItem()
{
	_pf_packetId = static_cast<int8_t>(0xC9);
	_pf_initialized = false;
}

PlayerListItem::PlayerListItem(const String16& _playerName, bool _online, int16_t _ping)
	:	_pf_playerName(_playerName)
	,	_pf_online(_online)
	,	_pf_ping(_ping)
{
	_pf_packetId = static_cast<int8_t>(0xC9);
	_pf_initialized = true;
}


size_t PlayerListItem::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_playerName);
	_offset = WriteBool(_dst, _offset, _pf_online);
	_offset = WriteInt16(_dst, _offset, _pf_ping);


	return _offset;
}

size_t PlayerListItem::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_playerName);
	_offset = ReadBool(_src, _offset, _pf_online);
	_offset = ReadInt16(_src, _offset, _pf_ping);
	_pf_initialized = true;
	return _offset;
}

const String16& PlayerListItem::getPlayerName() const { return _pf_playerName; }
bool PlayerListItem::getOnline() const { return _pf_online; }
int16_t PlayerListItem::getPing() const { return _pf_ping; }

void PlayerListItem::setPlayerName(const String16& _val) { _pf_playerName = _val; }
void PlayerListItem::setOnline(bool _val) { _pf_online = _val; }
void PlayerListItem::setPing(int16_t _val) { _pf_ping = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
