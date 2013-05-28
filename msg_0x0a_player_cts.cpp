#include "msg_0x0a_player_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Player::Player()
{
	_pf_packetId = static_cast<int8_t>(0x0A);
	_pf_initialized = false;
}

Player::Player(bool _onGround)
	:	_pf_onGround(_onGround)
{
	_pf_packetId = static_cast<int8_t>(0x0A);
	_pf_initialized = true;
}


size_t Player::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteBool(_dst, _offset, _pf_onGround);


	return _offset;
}

size_t Player::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadBool(_src, _offset, _pf_onGround);
	_pf_initialized = true;
	return _offset;
}

bool Player::getOnGround() const { return _pf_onGround; }

void Player::setOnGround(bool _val) { _pf_onGround = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
