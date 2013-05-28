#include "msg_0x13_entityaction_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityAction::EntityAction()
{
	_pf_packetId = static_cast<int8_t>(0x13);
	_pf_initialized = false;
}

EntityAction::EntityAction(int32_t _entityId, int8_t _actionId)
	:	_pf_entityId(_entityId)
	,	_pf_actionId(_actionId)
{
	_pf_packetId = static_cast<int8_t>(0x13);
	_pf_initialized = true;
}


size_t EntityAction::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_actionId);


	return _offset;
}

size_t EntityAction::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_actionId);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityAction::getEntityId() const { return _pf_entityId; }
int8_t EntityAction::getActionId() const { return _pf_actionId; }

void EntityAction::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityAction::setActionId(int8_t _val) { _pf_actionId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
