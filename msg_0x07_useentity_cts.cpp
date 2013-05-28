#include "msg_0x07_useentity_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

UseEntity::UseEntity()
{
	_pf_packetId = static_cast<int8_t>(0x07);
	_pf_initialized = false;
}

UseEntity::UseEntity(int32_t _user, int32_t _target, bool _button)
	:	_pf_user(_user)
	,	_pf_target(_target)
	,	_pf_button(_button)
{
	_pf_packetId = static_cast<int8_t>(0x07);
	_pf_initialized = true;
}


size_t UseEntity::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_user);
	_offset = WriteInt32(_dst, _offset, _pf_target);
	_offset = WriteBool(_dst, _offset, _pf_button);


	return _offset;
}

size_t UseEntity::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_user);
	_offset = ReadInt32(_src, _offset, _pf_target);
	_offset = ReadBool(_src, _offset, _pf_button);
	_pf_initialized = true;
	return _offset;
}

int32_t UseEntity::getUser() const { return _pf_user; }
int32_t UseEntity::getTarget() const { return _pf_target; }
bool UseEntity::getButton() const { return _pf_button; }

void UseEntity::setUser(int32_t _val) { _pf_user = _val; }
void UseEntity::setTarget(int32_t _val) { _pf_target = _val; }
void UseEntity::setButton(bool _val) { _pf_button = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
