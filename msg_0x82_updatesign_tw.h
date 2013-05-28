#ifndef _MSG_0X82_UPDATESIGN_TW_H_
#define _MSG_0X82_UPDATESIGN_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class UpdateSign : public BaseMessage
{
public:
	UpdateSign();
	UpdateSign(int32_t _x, int16_t _y, int32_t _z, const String16& _text1, const String16& _text2, const String16& _text3, const String16& _text4);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getX() const;
	int16_t getY() const;
	int32_t getZ() const;
	const String16& getText1() const;
	const String16& getText2() const;
	const String16& getText3() const;
	const String16& getText4() const;

	void setX(int32_t _val);
	void setY(int16_t _val);
	void setZ(int32_t _val);
	void setText1(const String16& _val);
	void setText2(const String16& _val);
	void setText3(const String16& _val);
	void setText4(const String16& _val);


private:
	int32_t _pf_x;
	int16_t _pf_y;
	int32_t _pf_z;
	String16 _pf_text1;
	String16 _pf_text2;
	String16 _pf_text3;
	String16 _pf_text4;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X82_UPDATESIGN_TW_H_