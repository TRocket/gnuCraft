#ifndef _MSG_0X2B_SETEXPERIENCE_STC_H_
#define _MSG_0X2B_SETEXPERIENCE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SetExperience : public BaseMessage
{
public:
	SetExperience();
	SetExperience(float _experienceBar, int16_t _level, int16_t _totalExperience);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	float getExperienceBar() const;
	int16_t getLevel() const;
	int16_t getTotalExperience() const;

	void setExperienceBar(float _val);
	void setLevel(int16_t _val);
	void setTotalExperience(int16_t _val);


private:
	float _pf_experienceBar;
	int16_t _pf_level;
	int16_t _pf_totalExperience;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X2B_SETEXPERIENCE_STC_H_