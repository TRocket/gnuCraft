#include "msg_0x09_respawn_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Respawn::Respawn()
{
	_pf_packetId = static_cast<int8_t>(0x09);
	_pf_initialized = false;
}

Respawn::Respawn(int32_t _dimension, int8_t _difficulty, int8_t _gameMode, int16_t _worldHeight, const String16& _levelType)
	:	_pf_dimension(_dimension)
	,	_pf_difficulty(_difficulty)
	,	_pf_gameMode(_gameMode)
	,	_pf_worldHeight(_worldHeight)
	,	_pf_levelType(_levelType)
{
	_pf_packetId = static_cast<int8_t>(0x09);
	_pf_initialized = true;
}


size_t Respawn::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_dimension);
	_offset = WriteInt8(_dst, _offset, _pf_difficulty);
	_offset = WriteInt8(_dst, _offset, _pf_gameMode);
	_offset = WriteInt16(_dst, _offset, _pf_worldHeight);
	_offset = WriteString16(_dst, _offset, _pf_levelType);


	return _offset;
}

size_t Respawn::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_dimension);
	_offset = ReadInt8(_src, _offset, _pf_difficulty);
	_offset = ReadInt8(_src, _offset, _pf_gameMode);
	_offset = ReadInt16(_src, _offset, _pf_worldHeight);
	_offset = ReadString16(_src, _offset, _pf_levelType);
	_pf_initialized = true;
	return _offset;
}

int32_t Respawn::getDimension() const { return _pf_dimension; }
int8_t Respawn::getDifficulty() const { return _pf_difficulty; }
int8_t Respawn::getGameMode() const { return _pf_gameMode; }
int16_t Respawn::getWorldHeight() const { return _pf_worldHeight; }
const String16& Respawn::getLevelType() const { return _pf_levelType; }

void Respawn::setDimension(int32_t _val) { _pf_dimension = _val; }
void Respawn::setDifficulty(int8_t _val) { _pf_difficulty = _val; }
void Respawn::setGameMode(int8_t _val) { _pf_gameMode = _val; }
void Respawn::setWorldHeight(int16_t _val) { _pf_worldHeight = _val; }
void Respawn::setLevelType(const String16& _val) { _pf_levelType = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
