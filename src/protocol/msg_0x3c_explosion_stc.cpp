#include "msg_0x3c_explosion_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Explosion::Explosion()
{
	_pf_packetId = static_cast<int8_t>(0x3C);
	_pf_initialized = false;
}

Explosion::Explosion(double _x, double _y, double _z, float _radius, int32_t _recordCount, const ByteArray& _records, float _playerMotionX, float _playerMotionY, float _playerMotionZ)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_radius(_radius)
	,	_pf_recordCount(_recordCount)
	,	_pf_records(_records)
	,	_pf_playerMotionX(_playerMotionX)
	,	_pf_playerMotionY(_playerMotionY)
	,	_pf_playerMotionZ(_playerMotionZ)
{
	_pf_packetId = static_cast<int8_t>(0x3C);
	_pf_initialized = true;
}


size_t Explosion::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteDouble(_dst, _offset, _pf_x);
	_offset = WriteDouble(_dst, _offset, _pf_y);
	_offset = WriteDouble(_dst, _offset, _pf_z);
	_offset = WriteFloat(_dst, _offset, _pf_radius);
	_offset = WriteInt32(_dst, _offset, _pf_recordCount);
	_offset = WriteByteArray(_dst, _offset, _pf_records);
	_offset = WriteFloat(_dst, _offset, _pf_playerMotionX);
	_offset = WriteFloat(_dst, _offset, _pf_playerMotionY);
	_offset = WriteFloat(_dst, _offset, _pf_playerMotionZ);


	return _offset;
}

size_t Explosion::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadDouble(_src, _offset, _pf_x);
	_offset = ReadDouble(_src, _offset, _pf_y);
	_offset = ReadDouble(_src, _offset, _pf_z);
	_offset = ReadFloat(_src, _offset, _pf_radius);
	_offset = ReadInt32(_src, _offset, _pf_recordCount);
	_offset = ReadByteArray(_src, _offset, _pf_recordCount * 3, _pf_records);
	_offset = ReadFloat(_src, _offset, _pf_playerMotionX);
	_offset = ReadFloat(_src, _offset, _pf_playerMotionY);
	_offset = ReadFloat(_src, _offset, _pf_playerMotionZ);
	_pf_initialized = true;
	return _offset;
}

double Explosion::getX() const { return _pf_x; }
double Explosion::getY() const { return _pf_y; }
double Explosion::getZ() const { return _pf_z; }
float Explosion::getRadius() const { return _pf_radius; }
int32_t Explosion::getRecordCount() const { return _pf_recordCount; }
const ByteArray& Explosion::getRecords() const { return _pf_records; }
float Explosion::getPlayerMotionX() const { return _pf_playerMotionX; }
float Explosion::getPlayerMotionY() const { return _pf_playerMotionY; }
float Explosion::getPlayerMotionZ() const { return _pf_playerMotionZ; }

void Explosion::setX(double _val) { _pf_x = _val; }
void Explosion::setY(double _val) { _pf_y = _val; }
void Explosion::setZ(double _val) { _pf_z = _val; }
void Explosion::setRadius(float _val) { _pf_radius = _val; }
void Explosion::setRecordCount(int32_t _val) { _pf_recordCount = _val; }
void Explosion::setRecords(const ByteArray& _val) { _pf_records = _val; }
void Explosion::setPlayerMotionX(float _val) { _pf_playerMotionX = _val; }
void Explosion::setPlayerMotionY(float _val) { _pf_playerMotionY = _val; }
void Explosion::setPlayerMotionZ(float _val) { _pf_playerMotionZ = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
