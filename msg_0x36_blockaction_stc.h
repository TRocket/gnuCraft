#ifndef _MSG_0X36_BLOCKACTION_STC_H_
#define _MSG_0X36_BLOCKACTION_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class BlockAction : public BaseMessage
{
public:
	BlockAction();
	BlockAction(int32_t _x, int16_t _y, int32_t _z, int8_t _byte1, int8_t _byte2, int16_t _blockId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getX() const;
	int16_t getY() const;
	int32_t getZ() const;
	int8_t getByte1() const;
	int8_t getByte2() const;
	int16_t getBlockId() const;

	void setX(int32_t _val);
	void setY(int16_t _val);
	void setZ(int32_t _val);
	void setByte1(int8_t _val);
	void setByte2(int8_t _val);
	void setBlockId(int16_t _val);


private:
	int32_t _pf_x;
	int16_t _pf_y;
	int32_t _pf_z;
	int8_t _pf_byte1;
	int8_t _pf_byte2;
	int16_t _pf_blockId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X36_BLOCKACTION_STC_H_