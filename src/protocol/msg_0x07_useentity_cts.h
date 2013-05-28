#ifndef _MSG_0X07_USEENTITY_CTS_H_
#define _MSG_0X07_USEENTITY_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class UseEntity : public BaseMessage
{
public:
	UseEntity();
	UseEntity(int32_t _user, int32_t _target, bool _button);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getUser() const;
	int32_t getTarget() const;
	bool getButton() const;

	void setUser(int32_t _val);
	void setTarget(int32_t _val);
	void setButton(bool _val);


private:
	int32_t _pf_user;
	int32_t _pf_target;
	bool _pf_button;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X07_USEENTITY_CTS_H_