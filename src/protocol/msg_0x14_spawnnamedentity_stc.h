#ifndef _MSG_0X14_SPAWNNAMEDENTITY_STC_H_
#define _MSG_0X14_SPAWNNAMEDENTITY_STC_H_

#include "mcprotocol_base.h"
#include "metadata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class SpawnNamedEntity : public BaseMessage
{
public:
	SpawnNamedEntity();
	SpawnNamedEntity(int32_t _playerId, const String16& _playerName, int32_t _x, int32_t _y, int32_t _z, int8_t _yaw, int8_t _pitch, int16_t _currentItem);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getPlayerId() const;
	const String16& getPlayerName() const;
	int32_t getX() const;
	int32_t getY() const;
	int32_t getZ() const;
	int8_t getYaw() const;
	int8_t getPitch() const;
	int16_t getCurrentItem() const;

	void setPlayerId(int32_t _val);
	void setPlayerName(const String16& _val);
	void setX(int32_t _val);
	void setY(int32_t _val);
	void setZ(int32_t _val);
	void setYaw(int8_t _val);
	void setPitch(int8_t _val);
	void setCurrentItem(int16_t _val);


private:
	int32_t _pf_playerId;
	String16 _pf_playerName;
	int32_t _pf_x;
	int32_t _pf_y;
	int32_t _pf_z;
	int8_t _pf_yaw;
	int8_t _pf_pitch;
	int16_t _pf_currentItem;
	Metadata _pf_metadata;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X14_SPAWNNAMEDENTITY_STC_H_