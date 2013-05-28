#include "msg_0x35_blockchange_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

BlockChange::BlockChange()
{
	_pf_packetId = static_cast<int8_t>(0x35);
	_pf_initialized = false;
}

BlockChange::BlockChange(int32_t _x, int8_t _y, int32_t _z, int16_t _blockType, int8_t _blockMetadata)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_blockType(_blockType)
	,	_pf_blockMetadata(_blockMetadata)
{
	_pf_packetId = static_cast<int8_t>(0x35);
	_pf_initialized = true;
}


size_t BlockChange::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt8(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt16(_dst, _offset, _pf_blockType);
	_offset = WriteInt8(_dst, _offset, _pf_blockMetadata);


	return _offset;
}

size_t BlockChange::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt8(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt16(_src, _offset, _pf_blockType);
	_offset = ReadInt8(_src, _offset, _pf_blockMetadata);
	_pf_initialized = true;
	return _offset;
}

int32_t BlockChange::getX() const { return _pf_x; }
int8_t BlockChange::getY() const { return _pf_y; }
int32_t BlockChange::getZ() const { return _pf_z; }
int16_t BlockChange::getBlockType() const { return _pf_blockType; }
int8_t BlockChange::getBlockMetadata() const { return _pf_blockMetadata; }

void BlockChange::setX(int32_t _val) { _pf_x = _val; }
void BlockChange::setY(int8_t _val) { _pf_y = _val; }
void BlockChange::setZ(int32_t _val) { _pf_z = _val; }
void BlockChange::setBlockType(int16_t _val) { _pf_blockType = _val; }
void BlockChange::setBlockMetadata(int8_t _val) { _pf_blockMetadata = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
