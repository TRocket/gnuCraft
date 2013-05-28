#ifndef _MSG_0X3C_EXPLOSION_STC_H_
#define _MSG_0X3C_EXPLOSION_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Explosion : public BaseMessage
{
public:
	Explosion();
	Explosion(double _x, double _y, double _z, float _radius, int32_t _recordCount, const ByteArray& _records, float _playerMotionX, float _playerMotionY, float _playerMotionZ);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	double getX() const;
	double getY() const;
	double getZ() const;
	float getRadius() const;
	int32_t getRecordCount() const;
	const ByteArray& getRecords() const;
	float getPlayerMotionX() const;
	float getPlayerMotionY() const;
	float getPlayerMotionZ() const;

	void setX(double _val);
	void setY(double _val);
	void setZ(double _val);
	void setRadius(float _val);
	void setRecordCount(int32_t _val);
	void setRecords(const ByteArray& _val);
	void setPlayerMotionX(float _val);
	void setPlayerMotionY(float _val);
	void setPlayerMotionZ(float _val);


private:
	double _pf_x;
	double _pf_y;
	double _pf_z;
	float _pf_radius;
	int32_t _pf_recordCount;
	ByteArray _pf_records;
	float _pf_playerMotionX;
	float _pf_playerMotionY;
	float _pf_playerMotionZ;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X3C_EXPLOSION_STC_H_