#ifndef _MSG_0X0F_PLAYERBLOCKPLACEMENT_CTS_H_
#define _MSG_0X0F_PLAYERBLOCKPLACEMENT_CTS_H_

#include "mcprotocol_base.h"
#include "slotdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class PlayerBlockPlacement : public BaseMessage
{
public:
	PlayerBlockPlacement();
	PlayerBlockPlacement(int32_t _x, int8_t _y, int32_t _z, int8_t _directioin, SlotData _heldItem, int8_t _cursorX, int8_t _cursorY, int8_t _cursorZ);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getX() const;
	int8_t getY() const;
	int32_t getZ() const;
	int8_t getDirectioin() const;
	SlotData getHeldItem() const;
	int8_t getCursorX() const;
	int8_t getCursorY() const;
	int8_t getCursorZ() const;

	void setX(int32_t _val);
	void setY(int8_t _val);
	void setZ(int32_t _val);
	void setDirectioin(int8_t _val);
	void setHeldItem(SlotData _val);
	void setCursorX(int8_t _val);
	void setCursorY(int8_t _val);
	void setCursorZ(int8_t _val);


private:
	int32_t _pf_x;
	int8_t _pf_y;
	int32_t _pf_z;
	int8_t _pf_directioin;
	SlotData _pf_heldItem;
	int8_t _pf_cursorX;
	int8_t _pf_cursorY;
	int8_t _pf_cursorZ;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X0F_PLAYERBLOCKPLACEMENT_CTS_H_