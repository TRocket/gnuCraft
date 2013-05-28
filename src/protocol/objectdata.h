#ifndef _OBJECTDATA_H_
#define _OBJECTDATA_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ObjectData : public BaseMessage
{
public:
	ObjectData();
	ObjectData(int32_t _intField, int16_t _xSpeed, int16_t _ySpeed, int16_t _zSpeed);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getIntField() const;
	int16_t getXSpeed() const;
	int16_t getYSpeed() const;
	int16_t getZSpeed() const;

	void setIntField(int32_t _val);
	void setXSpeed(int16_t _val);
	void setYSpeed(int16_t _val);
	void setZSpeed(int16_t _val);


private:
	int32_t _pf_intField;
	int16_t _pf_xSpeed;
	int16_t _pf_ySpeed;
	int16_t _pf_zSpeed;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XXX_OBJECTDATA__H_