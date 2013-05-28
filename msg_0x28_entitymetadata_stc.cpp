#include "msg_0x28_entitymetadata_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityMetadata::EntityMetadata()
{
	_pf_packetId = static_cast<int8_t>(0x28);
	_pf_initialized = false;
}

EntityMetadata::EntityMetadata(int32_t _entityId, Metadata _metadata)
	:	_pf_entityId(_entityId)
	,	_pf_metadata(_metadata)
{
	_pf_packetId = static_cast<int8_t>(0x28);
	_pf_initialized = true;
}


size_t EntityMetadata::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	//_offset = WriteMetadata(_dst, _offset, _pf_metadata);
	_offset = _pf_metadata.serialize(_dst, _offset);

	return _offset;
}

size_t EntityMetadata::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	//_offset = ReadMetadata(_src, _offset, _pf_metadata);
	_offset = _pf_metadata.deserialize(_src, _offset);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityMetadata::getEntityId() const { return _pf_entityId; }
Metadata EntityMetadata::getMetadata() const { return _pf_metadata; }

void EntityMetadata::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityMetadata::setMetadata(Metadata _val) { _pf_metadata = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
