#include "msg_0x0f_playerblockplacement_cts.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

PlayerBlockPlacement::PlayerBlockPlacement()
{
	_pf_packetId = static_cast<int8_t>(0x0F);
	_pf_initialized = false;
}

PlayerBlockPlacement::PlayerBlockPlacement(int32_t _x, int8_t _y, int32_t _z, int8_t _directioin, SlotData _heldItem, int8_t _cursorX, int8_t _cursorY, int8_t _cursorZ)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_directioin(_directioin)
	,	_pf_heldItem(_heldItem)
	,	_pf_cursorX(_cursorX)
	,	_pf_cursorY(_cursorY)
	,	_pf_cursorZ(_cursorZ)
{
	_pf_packetId = static_cast<int8_t>(0x0F);
	_pf_initialized = true;
}


size_t PlayerBlockPlacement::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt8(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt8(_dst, _offset, _pf_directioin);
	//_offset = WriteSlotData(_dst, _offset, _pf_heldItem);
	_offset = _pf_heldItem.serialize(_dst, _offset);
	_offset = WriteInt8(_dst, _offset, _pf_cursorX);
	_offset = WriteInt8(_dst, _offset, _pf_cursorY);
	_offset = WriteInt8(_dst, _offset, _pf_cursorZ);


	return _offset;
}

size_t PlayerBlockPlacement::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt8(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_directioin);
	//_offset = ReadSlotData(_src, _offset, _pf_heldItem);
	_offset = _pf_heldItem.deserialize(_src, _offset);
	_offset = ReadInt8(_src, _offset, _pf_cursorX);
	_offset = ReadInt8(_src, _offset, _pf_cursorY);
	_offset = ReadInt8(_src, _offset, _pf_cursorZ);
	_pf_initialized = true;
	return _offset;
}

int32_t PlayerBlockPlacement::getX() const { return _pf_x; }
int8_t PlayerBlockPlacement::getY() const { return _pf_y; }
int32_t PlayerBlockPlacement::getZ() const { return _pf_z; }
int8_t PlayerBlockPlacement::getDirectioin() const { return _pf_directioin; }
SlotData PlayerBlockPlacement::getHeldItem() const { return _pf_heldItem; }
int8_t PlayerBlockPlacement::getCursorX() const { return _pf_cursorX; }
int8_t PlayerBlockPlacement::getCursorY() const { return _pf_cursorY; }
int8_t PlayerBlockPlacement::getCursorZ() const { return _pf_cursorZ; }

void PlayerBlockPlacement::setX(int32_t _val) { _pf_x = _val; }
void PlayerBlockPlacement::setY(int8_t _val) { _pf_y = _val; }
void PlayerBlockPlacement::setZ(int32_t _val) { _pf_z = _val; }
void PlayerBlockPlacement::setDirectioin(int8_t _val) { _pf_directioin = _val; }
void PlayerBlockPlacement::setHeldItem(SlotData _val) { _pf_heldItem = _val; }
void PlayerBlockPlacement::setCursorX(int8_t _val) { _pf_cursorX = _val; }
void PlayerBlockPlacement::setCursorY(int8_t _val) { _pf_cursorY = _val; }
void PlayerBlockPlacement::setCursorZ(int8_t _val) { _pf_cursorZ = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
