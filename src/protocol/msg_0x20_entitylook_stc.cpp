#include "msg_0x20_entitylook_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

EntityLook::EntityLook()
{
	_pf_packetId = static_cast<int8_t>(0x20);
	_pf_initialized = false;
}

EntityLook::EntityLook(int32_t _entityId, int8_t _yaw, int8_t _pitch)
	:	_pf_entityId(_entityId)
	,	_pf_yaw(_yaw)
	,	_pf_pitch(_pitch)
{
	_pf_packetId = static_cast<int8_t>(0x20);
	_pf_initialized = true;
}


size_t EntityLook::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_entityId);
	_offset = WriteInt8(_dst, _offset, _pf_yaw);
	_offset = WriteInt8(_dst, _offset, _pf_pitch);


	return _offset;
}

size_t EntityLook::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_entityId);
	_offset = ReadInt8(_src, _offset, _pf_yaw);
	_offset = ReadInt8(_src, _offset, _pf_pitch);
	_pf_initialized = true;
	return _offset;
}

int32_t EntityLook::getEntityId() const { return _pf_entityId; }
int8_t EntityLook::getYaw() const { return _pf_yaw; }
int8_t EntityLook::getPitch() const { return _pf_pitch; }

void EntityLook::setEntityId(int32_t _val) { _pf_entityId = _val; }
void EntityLook::setYaw(int8_t _val) { _pf_yaw = _val; }
void EntityLook::setPitch(int8_t _val) { _pf_pitch = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
