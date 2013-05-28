#ifndef _MSG_0XCA_PLAYERABILITIES_TW_H_
#define _MSG_0XCA_PLAYERABILITIES_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

// Player Abilities (0xCA) Two-Way 
// http://mc.kev009.com/Protocol#Player_Abilities_.280xCA.29

class PlayerAbilities : public BaseMessage
{
public:
	PlayerAbilities();
	// Конструктор-заполнитель
	PlayerAbilities(bool _flagIsFlying);
	// Понадобится второй заполнитель для сервера

	// Сериализация
	size_t serialize(Buffer& _dst, size_t _offset);
	// Десериализация
	size_t deserialize(const Buffer& _dst, size_t _offset);

	// Геттеры
	//Sint8 getFlags() const; // потом заменится на bool'ы
	int8_t getFlyingSpeed() const;
	int8_t getWalkingSpeed() const;

private:

	enum Mask
	{
		MASK_CREATIVE = 1,
		MASK_ISFLYING = 2,
		MASK_CANFLY = 4,
		MASK_GODMODE = 8,
	};

	//Sint8 _pf_flags; // можно будет разделить флаги на 4 bool и автоматически заполнять при десериализации
	bool _pf_flagCreative, _pf_flagIsFlying, _pf_flagCanFly, _pf_flagGodmode;
	int8_t _pf_flyingSpeed;
	int8_t _pf_walkingSpeed;

};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XCA_PLAYERABILITIES_TW_H_