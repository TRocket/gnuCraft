#include "msg_0x3f_particle_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Particle::Particle()
{
	_pf_packetId = static_cast<int8_t>(0x3F);
	_pf_initialized = false;
}

Particle::Particle(const String16& _particleName, float _x, float _y, float _z, float _offsetX, float _offsetY, float _offsetZ, float _particleSpeed, int32_t _numOfParticles)
	:	_pf_particleName(_particleName)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_offsetX(_offsetX)
	,	_pf_offsetY(_offsetY)
	,	_pf_offsetZ(_offsetZ)
	,	_pf_particleSpeed(_particleSpeed)
	,	_pf_numOfParticles(_numOfParticles)
{
	_pf_packetId = static_cast<int8_t>(0x3F);
	_pf_initialized = true;
}


size_t Particle::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_particleName);
	_offset = WriteFloat(_dst, _offset, _pf_x);
	_offset = WriteFloat(_dst, _offset, _pf_y);
	_offset = WriteFloat(_dst, _offset, _pf_z);
	_offset = WriteFloat(_dst, _offset, _pf_offsetX);
	_offset = WriteFloat(_dst, _offset, _pf_offsetY);
	_offset = WriteFloat(_dst, _offset, _pf_offsetZ);
	_offset = WriteFloat(_dst, _offset, _pf_particleSpeed);
	_offset = WriteInt32(_dst, _offset, _pf_numOfParticles);


	return _offset;
}

size_t Particle::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_particleName);
	_offset = ReadFloat(_src, _offset, _pf_x);
	_offset = ReadFloat(_src, _offset, _pf_y);
	_offset = ReadFloat(_src, _offset, _pf_z);
	_offset = ReadFloat(_src, _offset, _pf_offsetX);
	_offset = ReadFloat(_src, _offset, _pf_offsetY);
	_offset = ReadFloat(_src, _offset, _pf_offsetZ);
	_offset = ReadFloat(_src, _offset, _pf_particleSpeed);
	_offset = ReadInt32(_src, _offset, _pf_numOfParticles);
	_pf_initialized = true;
	return _offset;
}

const String16& Particle::getParticleName() const { return _pf_particleName; }
float Particle::getX() const { return _pf_x; }
float Particle::getY() const { return _pf_y; }
float Particle::getZ() const { return _pf_z; }
float Particle::getOffsetX() const { return _pf_offsetX; }
float Particle::getOffsetY() const { return _pf_offsetY; }
float Particle::getOffsetZ() const { return _pf_offsetZ; }
float Particle::getParticleSpeed() const { return _pf_particleSpeed; }
int32_t Particle::getNumOfParticles() const { return _pf_numOfParticles; }

void Particle::setParticleName(const String16& _val) { _pf_particleName = _val; }
void Particle::setX(float _val) { _pf_x = _val; }
void Particle::setY(float _val) { _pf_y = _val; }
void Particle::setZ(float _val) { _pf_z = _val; }
void Particle::setOffsetX(float _val) { _pf_offsetX = _val; }
void Particle::setOffsetY(float _val) { _pf_offsetY = _val; }
void Particle::setOffsetZ(float _val) { _pf_offsetZ = _val; }
void Particle::setParticleSpeed(float _val) { _pf_particleSpeed = _val; }
void Particle::setNumOfParticles(int32_t _val) { _pf_numOfParticles = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
