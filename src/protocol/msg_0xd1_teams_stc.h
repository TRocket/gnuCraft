#ifndef _MSG_0XD1_TEAMS_STC_
#define _MSG_0XD1_TEAMS_STC_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Teams : public BaseMessage
{
public:
	Teams();					// умолчательный конструктор
	// Вставить заполнитель

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

private:
	String16 _pf_teamName;

	// If 0 then the team is created.
	// If 1 then the team is removed.
	// If 2 the team team information is updated.
	// If 3 then new players are added to the team.
	// If 4 then players are removed from the team. 
	int8_t _pf_mode;

	String16 _pf_teamDisplayName;		// Only if Mode = 0 or 2.
	String16 _pf_teamPrefix;			// Only if Mode = 0 or 2. Displayed before the players' name that are part of this team.
	String16 _pf_teamSuffix;			// Only if Mode = 0 or 2. Displayed after the players' name that are part of this team.
	int8_t _pf_friendlyFire;			// Only if Mode = 0 or 2; 0 for off, 1 for on, 3 for seeing friendly invisibles
	int16_t _pf_playerCount;			// Only if Mode = 0 or 3 or 4. Number of players in the array
	std::vector<String16> _pf_players;	// Only if Mode = 0 or 3 or 4. Players to be added/remove from the team. 

};

} // namespace MC
} // namespace Protocol
} // namespace Msg

#endif // _MSG_0XD1_TEAMS_STC_