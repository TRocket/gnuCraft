#include "msg_0x2a_removeentityeffect_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

RemoveEntityEffect::RemoveEntityEffect()
{
	_pf_packetId = static_cast<int8_t>(0x2A);
	_pf_initialized = false;
}

RemoveEntityEffect::RemoveEntityEffect(int32_t _entityId, int32_t _effectId)
	:	_pf_entityId(_entityId)
	,	_pf_effectId(_effectId)
{
	_pf_packetId = static_cast<int8_t>(0x2A);
	_pf_initialized = true;
}


size_t RemoveEntityEffect::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt32(_dst, _offset, _pf_effectId);


	return _offset;
}

size_t RemoveEntityEffect::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt32(_src, _offset, _pf_effectId);
	_pf_initialized = true;
	return _offset;
}

int32_t RemoveEntityEffect::getEntityId() const { return _pf_entityId; }
int32_t RemoveEntityEffect::getEffectId() const { return _pf_effectId; }

void RemoveEntityEffect::setEntityId(int32_t _val) { _pf_entityId = _val; }
void RemoveEntityEffect::setEffectId(int32_t _val) { _pf_effectId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
