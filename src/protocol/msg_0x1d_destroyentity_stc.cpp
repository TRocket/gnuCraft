#include "msg_0x1d_destroyentity_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

DestroyEntity::DestroyEntity()
{
	_pf_packetId = static_cast<int8_t>(0x1D);
	_pf_initialized = false;
}

DestroyEntity::DestroyEntity(int8_t _entityCount, const std::vector<int32_t>& _entityIds)
	:	_pf_entityCount(_entityCount)
	,	_pf_entityIds(_entityIds)
{
	_pf_packetId = static_cast<int8_t>(0x1D);
	_pf_initialized = true;
}


size_t DestroyEntity::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_entityCount);

	for(int i = 0; i < _pf_entityCount; ++i)
		_offset = WriteInt32(_dst, _offset, _pf_entityIds[i]);
	
	return _offset;
}

size_t DestroyEntity::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_entityCount);

	_pf_entityIds.resize(_pf_entityCount);

	for(int i = 0; i < _pf_entityCount; ++i)
		_offset = ReadInt32(_src, _offset, _pf_entityIds[i]);

	_pf_initialized = true;
	return _offset;
}

int8_t DestroyEntity::getEntityCount() const { return _pf_entityCount; }

void DestroyEntity::setEntityCount(int8_t _val) { _pf_entityCount = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
