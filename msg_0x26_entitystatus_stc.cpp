#include "msg_0x26_entitystatus_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityStatus::EntityStatus()
{
	_pf_packetId = static_cast<int8_t>(0x26);
	_pf_initialized = false;
}

EntityStatus::EntityStatus(int32_t _entityId, int8_t _entityStatus)
	:	_pf_entityId(_entityId)
	,	_pf_entityStatus(_entityStatus)
{
	_pf_packetId = static_cast<int8_t>(0x26);
	_pf_initialized = true;
}


size_t EntityStatus::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_entityStatus);


	return _offset;
}

size_t EntityStatus::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_entityStatus);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityStatus::getEntityId() const { return _pf_entityId; }
int8_t EntityStatus::getEntityStatus() const { return _pf_entityStatus; }

void EntityStatus::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityStatus::setEntityStatus(int8_t _val) { _pf_entityStatus = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
