#include "msg_0x27_attachentity_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

AttachEntity::AttachEntity()
{
	_pf_packetId = static_cast<int8_t>(0x27);
	_pf_initialized = false;
}

AttachEntity::AttachEntity(int32_t _entityId, int32_t _vehicleId)
	:	_pf_entityId(_entityId)
	,	_pf_vehicleId(_vehicleId)
{
	_pf_packetId = static_cast<int8_t>(0x27);
	_pf_initialized = true;
}


size_t AttachEntity::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt32(_dst, _offset, _pf_vehicleId);


	return _offset;
}

size_t AttachEntity::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt32(_src, _offset, _pf_vehicleId);
	_pf_initialized = true;
	return _offset;
}

int32_t AttachEntity::getEntityId() const { return _pf_entityId; }
int32_t AttachEntity::getVehicleId() const { return _pf_vehicleId; }

void AttachEntity::setEntityId(int32_t _val) { _pf_entityId = _val; }
void AttachEntity::setVehicleId(int32_t _val) { _pf_vehicleId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
