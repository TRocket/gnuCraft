#ifndef _MSG_0X08_HEALTHUPDATE_STC_H_
#define _MSG_0X08_HEALTHUPDATE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class HealthUpdate : public BaseMessage
{
public:
	HealthUpdate();
	HealthUpdate(int16_t _health, int16_t _food, float _saturation);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int16_t getHealth() const;
	int16_t getFood() const;
	float getSaturation() const;

	void setHealth(int16_t _val);
	void setFood(int16_t _val);
	void setSaturation(float _val);


private:
	int16_t _pf_health;
	int16_t _pf_food;
	float _pf_saturation;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X08_HEALTHUPDATE_STC_H_