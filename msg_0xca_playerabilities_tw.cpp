#include "msg_0xca_playerabilities_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

PlayerAbilities::PlayerAbilities()
{
	_pf_packetId = 0xCA;
	_pf_initialized = false;
}

// Конструктор-заполнитель
PlayerAbilities::PlayerAbilities(bool _flagIsFlying)
	:	_pf_flagIsFlying(_flagIsFlying)
{
	_pf_packetId = 0xCA;
	_pf_initialized = true;
}


// Сериализация
size_t PlayerAbilities::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	_dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	int8_t flags = 0;
	flags = flags | MASK_ISFLYING;
	_offset = WriteInt8(_dst, _offset, flags);
	_offset = WriteInt8(_dst, _offset, _pf_flyingSpeed);
	_offset = WriteInt8(_dst, _offset, _pf_walkingSpeed);

	return _offset;
}

// Десериализация
size_t PlayerAbilities::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	// Разбор флагов
	int8_t flags;
	_offset = ReadInt8(_src, _offset, flags);
	_pf_flagCreative = flags & MASK_CREATIVE;
	_pf_flagIsFlying = flags & MASK_ISFLYING;
	_pf_flagCanFly   = flags & MASK_CANFLY;
	_pf_flagGodmode  = flags & MASK_GODMODE;

	_offset = ReadInt8(_src, _offset, _pf_flyingSpeed);
	_offset = ReadInt8(_src, _offset, _pf_walkingSpeed);

	return _offset;
}


// Геттеры
//Sint8 PlayerAbilities::getFlags() const			{ return _pf_flags; }
int8_t PlayerAbilities::getFlyingSpeed() const	{ return _pf_flyingSpeed; }
int8_t PlayerAbilities::getWalkingSpeed() const	{ return _pf_walkingSpeed; }

} // namespace Msg
} // namespace Protocol
} // namespace MC