#include "msg_0x29_entityeffect_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityEffect::EntityEffect()
{
	_pf_packetId = static_cast<int8_t>(0x29);
	_pf_initialized = false;
}

EntityEffect::EntityEffect(int32_t _entityId, int32_t _effectId, int8_t _amplifier, int16_t _duration)
	:	_pf_entityId(_entityId)
	,	_pf_effectId(_effectId)
	,	_pf_amplifier(_amplifier)
	,	_pf_duration(_duration)
{
	_pf_packetId = static_cast<int8_t>(0x29);
	_pf_initialized = true;
}


size_t EntityEffect::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt32(_dst, _offset, _pf_effectId);
	_offset = WriteInt8(_dst, _offset, _pf_amplifier);
	_offset = WriteInt16(_dst, _offset, _pf_duration);


	return _offset;
}

size_t EntityEffect::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt32(_src, _offset, _pf_effectId);
	_offset = ReadInt8(_src, _offset, _pf_amplifier);
	_offset = ReadInt16(_src, _offset, _pf_duration);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityEffect::getEntityId() const { return _pf_entityId; }
int32_t EntityEffect::getEffectId() const { return _pf_effectId; }
int8_t EntityEffect::getAmplifier() const { return _pf_amplifier; }
int16_t EntityEffect::getDuration() const { return _pf_duration; }

void EntityEffect::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityEffect::setEffectId(int32_t _val) { _pf_effectId = _val; }
void EntityEffect::setAmplifier(int8_t _val) { _pf_amplifier = _val; }
void EntityEffect::setDuration(int16_t _val) { _pf_duration = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
