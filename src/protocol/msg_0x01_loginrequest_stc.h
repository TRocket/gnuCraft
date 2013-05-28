#ifndef _MSG_0X01_LOGINREQUEST_STC_H_
#define _MSG_0X01_LOGINREQUEST_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class LoginRequest : public BaseMessage
{
public:
	LoginRequest();
	LoginRequest(int32_t _entityId, const String16& _levelType, int8_t _gameMode, int8_t _dimension, int8_t _difficulty, int8_t _unused, int8_t _maxPlayers);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	const String16& getLevelType() const;
	int8_t getGameMode() const;
	int8_t getDimension() const;
	int8_t getDifficulty() const;
	int8_t getUnused() const;
	int8_t getMaxPlayers() const;

	void setEntityId(int32_t _val);
	void setLevelType(const String16& _val);
	void setGameMode(int8_t _val);
	void setDimension(int8_t _val);
	void setDifficulty(int8_t _val);
	void setUnused(int8_t _val);
	void setMaxPlayers(int8_t _val);


private:
	int32_t _pf_entityId;
	String16 _pf_levelType;
	int8_t _pf_gameMode;
	int8_t _pf_dimension;
	int8_t _pf_difficulty;
	int8_t _pf_unused;
	int8_t _pf_maxPlayers;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X01_LOGINREQUEST_STC_H_