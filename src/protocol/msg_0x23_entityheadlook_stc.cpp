#include "msg_0x23_entityheadlook_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityHeadLook::EntityHeadLook()
{
	_pf_packetId = static_cast<int8_t>(0x23);
	_pf_initialized = false;
}

EntityHeadLook::EntityHeadLook(int32_t _entityId, int8_t _headYaw)
	:	_pf_entityId(_entityId)
	,	_pf_headYaw(_headYaw)
{
	_pf_packetId = static_cast<int8_t>(0x23);
	_pf_initialized = true;
}


size_t EntityHeadLook::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_headYaw);


	return _offset;
}

size_t EntityHeadLook::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_headYaw);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityHeadLook::getEntityId() const { return _pf_entityId; }
int8_t EntityHeadLook::getHeadYaw() const { return _pf_headYaw; }

void EntityHeadLook::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityHeadLook::setHeadYaw(int8_t _val) { _pf_headYaw = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
