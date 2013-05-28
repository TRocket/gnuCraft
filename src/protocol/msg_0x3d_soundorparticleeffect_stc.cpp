#include "msg_0x3d_soundorparticleeffect_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SoundOrParticleEffect::SoundOrParticleEffect()
{
	_pf_packetId = static_cast<int8_t>(0x3D);
	_pf_initialized = false;
}

SoundOrParticleEffect::SoundOrParticleEffect(int32_t _effectId, int32_t _x, int8_t _y, int32_t _z, int32_t _data, bool _disableRelativeVolume)
	:	_pf_effectId(_effectId)
	,	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_data(_data)
	,	_pf_disableRelativeVolume(_disableRelativeVolume)
{
	_pf_packetId = static_cast<int8_t>(0x3D);
	_pf_initialized = true;
}


size_t SoundOrParticleEffect::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_effectId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt8(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt32(_dst, _offset, _pf_data);
	_offset = WriteBool(_dst, _offset, _pf_disableRelativeVolume);


	return _offset;
}

size_t SoundOrParticleEffect::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_effectId);
	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt8(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt32(_src, _offset, _pf_data);
	_offset = ReadBool(_src, _offset, _pf_disableRelativeVolume);
	_pf_initialized = true;
	return _offset;
}

int32_t SoundOrParticleEffect::getEffectId() const { return _pf_effectId; }
int32_t SoundOrParticleEffect::getX() const { return _pf_x; }
int8_t SoundOrParticleEffect::getY() const { return _pf_y; }
int32_t SoundOrParticleEffect::getZ() const { return _pf_z; }
int32_t SoundOrParticleEffect::getData() const { return _pf_data; }
bool SoundOrParticleEffect::getDisableRelativeVolume() const { return _pf_disableRelativeVolume; }

void SoundOrParticleEffect::setEffectId(int32_t _val) { _pf_effectId = _val; }
void SoundOrParticleEffect::setX(int32_t _val) { _pf_x = _val; }
void SoundOrParticleEffect::setY(int8_t _val) { _pf_y = _val; }
void SoundOrParticleEffect::setZ(int32_t _val) { _pf_z = _val; }
void SoundOrParticleEffect::setData(int32_t _val) { _pf_data = _val; }
void SoundOrParticleEffect::setDisableRelativeVolume(bool _val) { _pf_disableRelativeVolume = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
