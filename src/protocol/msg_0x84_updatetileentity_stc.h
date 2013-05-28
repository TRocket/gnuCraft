#ifndef _MSG_0X84_UPDATETILEENTITY_STC_H_
#define _MSG_0X84_UPDATETILEENTITY_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class UpdateTileEntity : public BaseMessage
{
public:
	UpdateTileEntity();
	UpdateTileEntity(int32_t _x, int16_t _y, int32_t _z, int8_t _action, int16_t _dataLength, const ByteArray& _data);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getX() const;
	int16_t getY() const;
	int32_t getZ() const;
	int8_t getAction() const;
	int16_t getDataLength() const;
	const ByteArray& getData() const;

	void setX(int32_t _val);
	void setY(int16_t _val);
	void setZ(int32_t _val);
	void setAction(int8_t _val);
	void setDataLength(int16_t _val);
	void setData(const ByteArray& _val);


private:
	int32_t _pf_x;
	int16_t _pf_y;
	int32_t _pf_z;
	int8_t _pf_action;
	int16_t _pf_dataLength;
	ByteArray _pf_data;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X84_UPDATETILEENTITY_STC_H_