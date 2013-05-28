#include "msg_0x46_changegamestate_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ChangeGameState::ChangeGameState()
{
	_pf_packetId = static_cast<int8_t>(0x46);
	_pf_initialized = false;
}

ChangeGameState::ChangeGameState(int8_t _reason, int8_t _gameMode)
	:	_pf_reason(_reason)
	,	_pf_gameMode(_gameMode)
{
	_pf_packetId = static_cast<int8_t>(0x46);
	_pf_initialized = true;
}


size_t ChangeGameState::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_reason);
	_offset = WriteInt8(_dst, _offset, _pf_gameMode);


	return _offset;
}

size_t ChangeGameState::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_reason);
	_offset = ReadInt8(_src, _offset, _pf_gameMode);
	_pf_initialized = true;
	return _offset;
}

int8_t ChangeGameState::getReason() const { return _pf_reason; }
int8_t ChangeGameState::getGameMode() const { return _pf_gameMode; }

void ChangeGameState::setReason(int8_t _val) { _pf_reason = _val; }
void ChangeGameState::setGameMode(int8_t _val) { _pf_gameMode = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
