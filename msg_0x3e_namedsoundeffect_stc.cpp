#include "msg_0x3e_namedsoundeffect_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

NamedSoundEffect::NamedSoundEffect()
{
	_pf_packetId = static_cast<int8_t>(0x3E);
	_pf_initialized = false;
}

NamedSoundEffect::NamedSoundEffect(const String16& _soundName, int32_t _effectX, int32_t _effectY, int32_t _effectZ, float _volume, int8_t _pitch)
	:	_pf_soundName(_soundName)
	,	_pf_effectX(_effectX)
	,	_pf_effectY(_effectY)
	,	_pf_effectZ(_effectZ)
	,	_pf_volume(_volume)
	,	_pf_pitch(_pitch)
{
	_pf_packetId = static_cast<int8_t>(0x3E);
	_pf_initialized = true;
}


size_t NamedSoundEffect::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_soundName);
	_offset = WriteInt32(_dst, _offset, _pf_effectX);
	_offset = WriteInt32(_dst, _offset, _pf_effectY);
	_offset = WriteInt32(_dst, _offset, _pf_effectZ);
	_offset = WriteFloat(_dst, _offset, _pf_volume);
	_offset = WriteInt8(_dst, _offset, _pf_pitch);


	return _offset;
}

size_t NamedSoundEffect::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_soundName);
	_offset = ReadInt32(_src, _offset, _pf_effectX);
	_offset = ReadInt32(_src, _offset, _pf_effectY);
	_offset = ReadInt32(_src, _offset, _pf_effectZ);
	_offset = ReadFloat(_src, _offset, _pf_volume);
	_offset = ReadInt8(_src, _offset, _pf_pitch);
	_pf_initialized = true;
	return _offset;
}

const String16& NamedSoundEffect::getSoundName() const { return _pf_soundName; }
int32_t NamedSoundEffect::getEffectX() const { return _pf_effectX; }
int32_t NamedSoundEffect::getEffectY() const { return _pf_effectY; }
int32_t NamedSoundEffect::getEffectZ() const { return _pf_effectZ; }
float NamedSoundEffect::getVolume() const { return _pf_volume; }
int8_t NamedSoundEffect::getPitch() const { return _pf_pitch; }

void NamedSoundEffect::setSoundName(const String16& _val) { _pf_soundName = _val; }
void NamedSoundEffect::setEffectX(int32_t _val) { _pf_effectX = _val; }
void NamedSoundEffect::setEffectY(int32_t _val) { _pf_effectY = _val; }
void NamedSoundEffect::setEffectZ(int32_t _val) { _pf_effectZ = _val; }
void NamedSoundEffect::setVolume(float _val) { _pf_volume = _val; }
void NamedSoundEffect::setPitch(int8_t _val) { _pf_pitch = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
