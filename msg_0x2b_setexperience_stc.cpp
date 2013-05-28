#include "msg_0x2b_setexperience_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

SetExperience::SetExperience()
{
	_pf_packetId = static_cast<int8_t>(0x2B);
	_pf_initialized = false;
}

SetExperience::SetExperience(float _experienceBar, int16_t _level, int16_t _totalExperience)
	:	_pf_experienceBar(_experienceBar)
	,	_pf_level(_level)
	,	_pf_totalExperience(_totalExperience)
{
	_pf_packetId = static_cast<int8_t>(0x2B);
	_pf_initialized = true;
}


size_t SetExperience::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteFloat(_dst, _offset, _pf_experienceBar);
	_offset = WriteInt16(_dst, _offset, _pf_level);
	_offset = WriteInt16(_dst, _offset, _pf_totalExperience);


	return _offset;
}

size_t SetExperience::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadFloat(_src, _offset, _pf_experienceBar);
	_offset = ReadInt16(_src, _offset, _pf_level);
	_offset = ReadInt16(_src, _offset, _pf_totalExperience);
	_pf_initialized = true;
	return _offset;
}

float SetExperience::getExperienceBar() const { return _pf_experienceBar; }
int16_t SetExperience::getLevel() const { return _pf_level; }
int16_t SetExperience::getTotalExperience() const { return _pf_totalExperience; }

void SetExperience::setExperienceBar(float _val) { _pf_experienceBar = _val; }
void SetExperience::setLevel(int16_t _val) { _pf_level = _val; }
void SetExperience::setTotalExperience(int16_t _val) { _pf_totalExperience = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
