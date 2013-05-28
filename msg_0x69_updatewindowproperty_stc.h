#ifndef _MSG_0X69_UPDATEWINDOWPROPERTY_STC_H_
#define _MSG_0X69_UPDATEWINDOWPROPERTY_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class UpdateWindowProperty : public BaseMessage
{
public:
	UpdateWindowProperty();
	UpdateWindowProperty(int8_t _windowId, int16_t _property, int16_t _value);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getWindowId() const;
	int16_t getProperty() const;
	int16_t getValue() const;

	void setWindowId(int8_t _val);
	void setProperty(int16_t _val);
	void setValue(int16_t _val);


private:
	int8_t _pf_windowId;
	int16_t _pf_property;
	int16_t _pf_value;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X69_UPDATEWINDOWPROPERTY_STC_H_