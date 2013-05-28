#ifndef _MSG_0X3F_PARTICLE_STC_H_
#define _MSG_0X3F_PARTICLE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Particle : public BaseMessage
{
public:
	Particle();
	Particle(const String16& _particleName, float _x, float _y, float _z, float _offsetX, float _offsetY, float _offsetZ, float _particleSpeed, int32_t _numOfParticles);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getParticleName() const;
	float getX() const;
	float getY() const;
	float getZ() const;
	float getOffsetX() const;
	float getOffsetY() const;
	float getOffsetZ() const;
	float getParticleSpeed() const;
	int32_t getNumOfParticles() const;

	void setParticleName(const String16& _val);
	void setX(float _val);
	void setY(float _val);
	void setZ(float _val);
	void setOffsetX(float _val);
	void setOffsetY(float _val);
	void setOffsetZ(float _val);
	void setParticleSpeed(float _val);
	void setNumOfParticles(int32_t _val);


private:
	String16 _pf_particleName;
	float _pf_x;
	float _pf_y;
	float _pf_z;
	float _pf_offsetX;
	float _pf_offsetY;
	float _pf_offsetZ;
	float _pf_particleSpeed;
	int32_t _pf_numOfParticles;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X3F_PARTICLE_STC_H_