#include "msg_0x14_spawnnamedentity_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SpawnNamedEntity::SpawnNamedEntity()
{
	_pf_packetId = static_cast<int8_t>(0x14);
	_pf_initialized = false;
}

SpawnNamedEntity::SpawnNamedEntity(int32_t _playerId, const String16& _playerName, int32_t _x, int32_t _y, int32_t _z, int8_t _yaw, int8_t _pitch, int16_t _currentItem)
	:	_pf_playerId(_playerId)
	,	_pf_playerName(_playerName)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_yaw(_yaw)
	,	_pf_pitch(_pitch)
	,	_pf_currentItem(_currentItem)
{
	_pf_packetId = static_cast<int8_t>(0x14);
	_pf_initialized = true;
}


size_t SpawnNamedEntity::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_playerId);
	_offset = WriteString16(_dst, _offset, _pf_playerName);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt32(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt8(_dst, _offset, _pf_yaw);
	_offset = WriteInt8(_dst, _offset, _pf_pitch);
	_offset = WriteInt16(_dst, _offset, _pf_currentItem);


	return _offset;
}

size_t SpawnNamedEntity::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_playerId);
	_offset = ReadString16(_src, _offset, _pf_playerName);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt32(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_yaw);
	_offset = ReadInt8(_src, _offset, _pf_pitch);
	_offset = ReadInt16(_src, _offset, _pf_currentItem);
	_offset = _pf_metadata.deserialize(_src, _offset);

	_pf_initialized = true;
	return _offset;
}

int32_t SpawnNamedEntity::getPlayerId() const { return _pf_playerId; }
const String16& SpawnNamedEntity::getPlayerName() const { return _pf_playerName; }
int32_t SpawnNamedEntity::getX() const { return _pf_x; }
int32_t SpawnNamedEntity::getY() const { return _pf_y; }
int32_t SpawnNamedEntity::getZ() const { return _pf_z; }
int8_t SpawnNamedEntity::getYaw() const { return _pf_yaw; }
int8_t SpawnNamedEntity::getPitch() const { return _pf_pitch; }
int16_t SpawnNamedEntity::getCurrentItem() const { return _pf_currentItem; }

void SpawnNamedEntity::setPlayerId(int32_t _val) { _pf_playerId = _val; }
void SpawnNamedEntity::setPlayerName(const String16& _val) { _pf_playerName = _val; }
void SpawnNamedEntity::setX(int32_t _val) { _pf_x = _val; }
void SpawnNamedEntity::setY(int32_t _val) { _pf_y = _val; }
void SpawnNamedEntity::setZ(int32_t _val) { _pf_z = _val; }
void SpawnNamedEntity::setYaw(int8_t _val) { _pf_yaw = _val; }
void SpawnNamedEntity::setPitch(int8_t _val) { _pf_pitch = _val; }
void SpawnNamedEntity::setCurrentItem(int16_t _val) { _pf_currentItem = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
