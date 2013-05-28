#include "msg_0x36_blockaction_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

BlockAction::BlockAction()
{
	_pf_packetId = static_cast<int8_t>(0x36);
	_pf_initialized = false;
}

BlockAction::BlockAction(int32_t _x, int16_t _y, int32_t _z, int8_t _byte1, int8_t _byte2, int16_t _blockId)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_byte1(_byte1)
	,	_pf_byte2(_byte2)
	,	_pf_blockId(_blockId)
{
	_pf_packetId = static_cast<int8_t>(0x36);
	_pf_initialized = true;
}


size_t BlockAction::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt16(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt8(_dst, _offset, _pf_byte1);
	_offset = WriteInt8(_dst, _offset, _pf_byte2);
	_offset = WriteInt16(_dst, _offset, _pf_blockId);


	return _offset;
}

size_t BlockAction::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt16(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_byte1);
	_offset = ReadInt8(_src, _offset, _pf_byte2);
	_offset = ReadInt16(_src, _offset, _pf_blockId);
	_pf_initialized = true;
	return _offset;
}

int32_t BlockAction::getX() const { return _pf_x; }
int16_t BlockAction::getY() const { return _pf_y; }
int32_t BlockAction::getZ() const { return _pf_z; }
int8_t BlockAction::getByte1() const { return _pf_byte1; }
int8_t BlockAction::getByte2() const { return _pf_byte2; }
int16_t BlockAction::getBlockId() const { return _pf_blockId; }

void BlockAction::setX(int32_t _val) { _pf_x = _val; }
void BlockAction::setY(int16_t _val) { _pf_y = _val; }
void BlockAction::setZ(int32_t _val) { _pf_z = _val; }
void BlockAction::setByte1(int8_t _val) { _pf_byte1 = _val; }
void BlockAction::setByte2(int8_t _val) { _pf_byte2 = _val; }
void BlockAction::setBlockId(int16_t _val) { _pf_blockId = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
