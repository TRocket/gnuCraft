#include "msg_0x1e_entity_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Entity::Entity()
{
	_pf_packetId = static_cast<int8_t>(0x1E);
	_pf_initialized = false;
}

Entity::Entity(int32_t _entityId)
	:	_pf_entityId(_entityId)
{
	_pf_packetId = static_cast<int8_t>(0x1E);
	_pf_initialized = true;
}


size_t Entity::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);


	return _offset;
}

size_t Entity::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_pf_initialized = true;
	return _offset;
}

int32_t Entity::getEntityId() const { return _pf_entityId; }

void Entity::setEntityId(int32_t _val) { _pf_entityId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
