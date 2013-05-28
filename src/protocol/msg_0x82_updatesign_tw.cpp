#include "msg_0x82_updatesign_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

UpdateSign::UpdateSign()
{
	_pf_packetId = static_cast<int8_t>(0x82);
	_pf_initialized = false;
}

UpdateSign::UpdateSign(int32_t _x, int16_t _y, int32_t _z, const String16& _text1, const String16& _text2, const String16& _text3, const String16& _text4)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_text1(_text1)
	,	_pf_text2(_text2)
	,	_pf_text3(_text3)
	,	_pf_text4(_text4)
{
	_pf_packetId = static_cast<int8_t>(0x82);
	_pf_initialized = true;
}


size_t UpdateSign::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt16(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteString16(_dst, _offset, _pf_text1);
	_offset = WriteString16(_dst, _offset, _pf_text2);
	_offset = WriteString16(_dst, _offset, _pf_text3);
	_offset = WriteString16(_dst, _offset, _pf_text4);


	return _offset;
}

size_t UpdateSign::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt16(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadString16(_src, _offset, _pf_text1);
	_offset = ReadString16(_src, _offset, _pf_text2);
	_offset = ReadString16(_src, _offset, _pf_text3);
	_offset = ReadString16(_src, _offset, _pf_text4);
	_pf_initialized = true;
	return _offset;
}

int32_t UpdateSign::getX() const { return _pf_x; }
int16_t UpdateSign::getY() const { return _pf_y; }
int32_t UpdateSign::getZ() const { return _pf_z; }
const String16& UpdateSign::getText1() const { return _pf_text1; }
const String16& UpdateSign::getText2() const { return _pf_text2; }
const String16& UpdateSign::getText3() const { return _pf_text3; }
const String16& UpdateSign::getText4() const { return _pf_text4; }

void UpdateSign::setX(int32_t _val) { _pf_x = _val; }
void UpdateSign::setY(int16_t _val) { _pf_y = _val; }
void UpdateSign::setZ(int32_t _val) { _pf_z = _val; }
void UpdateSign::setText1(const String16& _val) { _pf_text1 = _val; }
void UpdateSign::setText2(const String16& _val) { _pf_text2 = _val; }
void UpdateSign::setText3(const String16& _val) { _pf_text3 = _val; }
void UpdateSign::setText4(const String16& _val) { _pf_text4 = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
