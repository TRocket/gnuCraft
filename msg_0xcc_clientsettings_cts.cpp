#include "msg_0xcc_clientsettings_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ClientSettings::ClientSettings()
{
	_pf_packetId = static_cast<int8_t>(0xCC);
	_pf_initialized = false;
}

ClientSettings::ClientSettings(const String16& _locale, int8_t _viewDistance, int8_t _chatFlags, int8_t _difficulty, bool _showCape)
	:	_pf_locale(_locale)
	,	_pf_viewDistance(_viewDistance)
	,	_pf_chatFlags(_chatFlags)
	,	_pf_difficulty(_difficulty)
	,	_pf_showCape(_showCape)
{
	_pf_packetId = static_cast<int8_t>(0xCC);
	_pf_initialized = true;
}


size_t ClientSettings::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_locale);
	_offset = WriteInt8(_dst, _offset, _pf_viewDistance);
	_offset = WriteInt8(_dst, _offset, _pf_chatFlags);
	_offset = WriteInt8(_dst, _offset, _pf_difficulty);
	_offset = WriteBool(_dst, _offset, _pf_showCape);


	return _offset;
}

size_t ClientSettings::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_locale);
	_offset = ReadInt8(_src, _offset, _pf_viewDistance);
	_offset = ReadInt8(_src, _offset, _pf_chatFlags);
	_offset = ReadInt8(_src, _offset, _pf_difficulty);
	_offset = ReadBool(_src, _offset, _pf_showCape);
	_pf_initialized = true;
	return _offset;
}

const String16& ClientSettings::getLocale() const { return _pf_locale; }
int8_t ClientSettings::getViewDistance() const { return _pf_viewDistance; }
int8_t ClientSettings::getChatFlags() const { return _pf_chatFlags; }
int8_t ClientSettings::getDifficulty() const { return _pf_difficulty; }
bool ClientSettings::getShowCape() const { return _pf_showCape; }

void ClientSettings::setLocale(const String16& _val) { _pf_locale = _val; }
void ClientSettings::setViewDistance(int8_t _val) { _pf_viewDistance = _val; }
void ClientSettings::setChatFlags(int8_t _val) { _pf_chatFlags = _val; }
void ClientSettings::setDifficulty(int8_t _val) { _pf_difficulty = _val; }
void ClientSettings::setShowCape(bool _val) { _pf_showCape = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
