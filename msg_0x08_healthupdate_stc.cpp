#include "msg_0x08_healthupdate_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

HealthUpdate::HealthUpdate()
{
	_pf_packetId = static_cast<int8_t>(0x08);
	_pf_initialized = false;
}

HealthUpdate::HealthUpdate(int16_t _health, int16_t _food, float _saturation)
	:	_pf_health(_health)
	,	_pf_food(_food)
	,	_pf_saturation(_saturation)
{
	_pf_packetId = static_cast<int8_t>(0x08);
	_pf_initialized = true;
}


size_t HealthUpdate::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt16(_dst, _offset, _pf_health);
	_offset = WriteInt16(_dst, _offset, _pf_food);
	_offset = WriteFloat(_dst, _offset, _pf_saturation);


	return _offset;
}

size_t HealthUpdate::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt16(_src, _offset, _pf_health);
	_offset = ReadInt16(_src, _offset, _pf_food);
	_offset = ReadFloat(_src, _offset, _pf_saturation);
	_pf_initialized = true;
	return _offset;
}

int16_t HealthUpdate::getHealth() const { return _pf_health; }
int16_t HealthUpdate::getFood() const { return _pf_food; }
float HealthUpdate::getSaturation() const { return _pf_saturation; }

void HealthUpdate::setHealth(int16_t _val) { _pf_health = _val; }
void HealthUpdate::setFood(int16_t _val) { _pf_food = _val; }
void HealthUpdate::setSaturation(float _val) { _pf_saturation = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
