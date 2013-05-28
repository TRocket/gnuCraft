#ifndef _MSG_0X09_RESPAWN_STC_H_
#define _MSG_0X09_RESPAWN_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Respawn : public BaseMessage
{
public:
	Respawn();
	Respawn(int32_t _dimension, int8_t _difficulty, int8_t _gameMode, int16_t _worldHeight, const String16& _levelType);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getDimension() const;
	int8_t getDifficulty() const;
	int8_t getGameMode() const;
	int16_t getWorldHeight() const;
	const String16& getLevelType() const;

	void setDimension(int32_t _val);
	void setDifficulty(int8_t _val);
	void setGameMode(int8_t _val);
	void setWorldHeight(int16_t _val);
	void setLevelType(const String16& _val);


private:
	int32_t _pf_dimension;
	int8_t _pf_difficulty;
	int8_t _pf_gameMode;
	int16_t _pf_worldHeight;
	String16 _pf_levelType;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X09_RESPAWN_STC_H_