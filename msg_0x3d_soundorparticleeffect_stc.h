#ifndef _MSG_0X3D_SOUNDORPARTICLEEFFECT_STC_H_
#define _MSG_0X3D_SOUNDORPARTICLEEFFECT_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SoundOrParticleEffect : public BaseMessage
{
public:
	SoundOrParticleEffect();
	SoundOrParticleEffect(int32_t _effectId, int32_t _x, int8_t _y, int32_t _z, int32_t _data, bool _disableRelativeVolume);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEffectId() const;
	int32_t getX() const;
	int8_t getY() const;
	int32_t getZ() const;
	int32_t getData() const;
	bool getDisableRelativeVolume() const;

	void setEffectId(int32_t _val);
	void setX(int32_t _val);
	void setY(int8_t _val);
	void setZ(int32_t _val);
	void setData(int32_t _val);
	void setDisableRelativeVolume(bool _val);


private:
	int32_t _pf_effectId;
	int32_t _pf_x;
	int8_t _pf_y;
	int32_t _pf_z;
	int32_t _pf_data;
	bool _pf_disableRelativeVolume;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X3D_SOUNDORPARTICLEEFFECT_STC_H_