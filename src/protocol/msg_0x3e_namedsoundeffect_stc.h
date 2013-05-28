#ifndef _MSG_0X3E_NAMEDSOUNDEFFECT_STC_H_
#define _MSG_0X3E_NAMEDSOUNDEFFECT_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class NamedSoundEffect : public BaseMessage
{
public:
	NamedSoundEffect();
	NamedSoundEffect(const String16& _soundName, int32_t _effectX, int32_t _effectY, int32_t _effectZ, float _volume, int8_t _pitch);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getSoundName() const;
	int32_t getEffectX() const;
	int32_t getEffectY() const;
	int32_t getEffectZ() const;
	float getVolume() const;
	int8_t getPitch() const;

	void setSoundName(const String16& _val);
	void setEffectX(int32_t _val);
	void setEffectY(int32_t _val);
	void setEffectZ(int32_t _val);
	void setVolume(float _val);
	void setPitch(int8_t _val);


private:
	String16 _pf_soundName;
	int32_t _pf_effectX;
	int32_t _pf_effectY;
	int32_t _pf_effectZ;
	float _pf_volume;
	int8_t _pf_pitch;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X3E_NAMEDSOUNDEFFECT_STC_H_