#ifndef _MSG_0X35_BLOCKCHANGE_STC_H_
#define _MSG_0X35_BLOCKCHANGE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class BlockChange : public BaseMessage
{
public:
	BlockChange();
	BlockChange(int32_t _x, int8_t _y, int32_t _z, int16_t _blockType, int8_t _blockMetadata);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getX() const;
	int8_t getY() const;
	int32_t getZ() const;
	int16_t getBlockType() const;
	int8_t getBlockMetadata() const;

	void setX(int32_t _val);
	void setY(int8_t _val);
	void setZ(int32_t _val);
	void setBlockType(int16_t _val);
	void setBlockMetadata(int8_t _val);


private:
	int32_t _pf_x;
	int8_t _pf_y;
	int32_t _pf_z;
	int16_t _pf_blockType;
	int8_t _pf_blockMetadata;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X35_BLOCKCHANGE_STC_H_