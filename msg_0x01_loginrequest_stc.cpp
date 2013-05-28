#include "msg_0x01_loginrequest_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

LoginRequest::LoginRequest()
{
	_pf_packetId = static_cast<int8_t>(0x01);
	_pf_initialized = false;
}

LoginRequest::LoginRequest(int32_t _entityId, const String16& _levelType, int8_t _gameMode, int8_t _dimension, int8_t _difficulty, int8_t _unused, int8_t _maxPlayers)
	:	_pf_entityId(_entityId)
	,	_pf_levelType(_levelType)
	,	_pf_gameMode(_gameMode)
	,	_pf_dimension(_dimension)
	,	_pf_difficulty(_difficulty)
	,	_pf_unused(_unused)
	,	_pf_maxPlayers(_maxPlayers)
{
	_pf_packetId = static_cast<int8_t>(0x01);
	_pf_initialized = true;
}


size_t LoginRequest::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteString16(_dst, _offset, _pf_levelType);
	_offset = WriteInt8(_dst, _offset, _pf_gameMode);
	_offset = WriteInt8(_dst, _offset, _pf_dimension);
	_offset = WriteInt8(_dst, _offset, _pf_difficulty);
	_offset = WriteInt8(_dst, _offset, _pf_unused);
	_offset = WriteInt8(_dst, _offset, _pf_maxPlayers);


	return _offset;
}

size_t LoginRequest::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadString16(_src, _offset, _pf_levelType);
	_offset = ReadInt8(_src, _offset, _pf_gameMode);
	_offset = ReadInt8(_src, _offset, _pf_dimension);
	_offset = ReadInt8(_src, _offset, _pf_difficulty);
	_offset = ReadInt8(_src, _offset, _pf_unused);
	_offset = ReadInt8(_src, _offset, _pf_maxPlayers);
	_pf_initialized = true;
	return _offset;
}

int32_t LoginRequest::getEntityId() const { return _pf_entityId; }
const String16& LoginRequest::getLevelType() const { return _pf_levelType; }
int8_t LoginRequest::getGameMode() const { return _pf_gameMode; }
int8_t LoginRequest::getDimension() const { return _pf_dimension; }
int8_t LoginRequest::getDifficulty() const { return _pf_difficulty; }
int8_t LoginRequest::getUnused() const { return _pf_unused; }
int8_t LoginRequest::getMaxPlayers() const { return _pf_maxPlayers; }

void LoginRequest::setEntityId(int32_t _val) { _pf_entityId = _val; }
void LoginRequest::setLevelType(const String16& _val) { _pf_levelType = _val; }
void LoginRequest::setGameMode(int8_t _val) { _pf_gameMode = _val; }
void LoginRequest::setDimension(int8_t _val) { _pf_dimension = _val; }
void LoginRequest::setDifficulty(int8_t _val) { _pf_difficulty = _val; }
void LoginRequest::setUnused(int8_t _val) { _pf_unused = _val; }
void LoginRequest::setMaxPlayers(int8_t _val) { _pf_maxPlayers = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
