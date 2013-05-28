#include "msg_0x84_updatetileentity_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

UpdateTileEntity::UpdateTileEntity()
{
	_pf_packetId = static_cast<int8_t>(0x84);
	_pf_initialized = false;
}

UpdateTileEntity::UpdateTileEntity(int32_t _x, int16_t _y, int32_t _z, int8_t _action, int16_t _dataLength, const ByteArray& _data)
	:	_pf_x(_x)
	,	_pf_y(_y)
	,	_pf_z(_z)
	,	_pf_action(_action)
	,	_pf_dataLength(_dataLength)
	,	_pf_data(_data)
{
	_pf_packetId = static_cast<int8_t>(0x84);
	_pf_initialized = true;
}


size_t UpdateTileEntity::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_x);
	_offset = WriteInt16(_dst, _offset, _pf_y);
	_offset = WriteInt32(_dst, _offset, _pf_z);
	_offset = WriteInt8(_dst, _offset, _pf_action);
	_offset = WriteInt16(_dst, _offset, _pf_dataLength);
	_offset = WriteByteArray(_dst, _offset, _pf_data);


	return _offset;
}

size_t UpdateTileEntity::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_x);
	_offset = ReadInt16(_src, _offset, _pf_y);
	_offset = ReadInt32(_src, _offset, _pf_z);
	_offset = ReadInt8(_src, _offset, _pf_action);
	_offset = ReadInt16(_src, _offset, _pf_dataLength);
	_offset = ReadByteArray(_src, _offset, _pf_dataLength, _pf_data);
	_pf_initialized = true;
	return _offset;
}

int32_t UpdateTileEntity::getX() const { return _pf_x; }
int16_t UpdateTileEntity::getY() const { return _pf_y; }
int32_t UpdateTileEntity::getZ() const { return _pf_z; }
int8_t UpdateTileEntity::getAction() const { return _pf_action; }
int16_t UpdateTileEntity::getDataLength() const { return _pf_dataLength; }
const ByteArray& UpdateTileEntity::getData() const { return _pf_data; }

void UpdateTileEntity::setX(int32_t _val) { _pf_x = _val; }
void UpdateTileEntity::setY(int16_t _val) { _pf_y = _val; }
void UpdateTileEntity::setZ(int32_t _val) { _pf_z = _val; }
void UpdateTileEntity::setAction(int8_t _val) { _pf_action = _val; }
void UpdateTileEntity::setDataLength(int16_t _val) { _pf_dataLength = _val; }
void UpdateTileEntity::setData(const ByteArray& _val) { _pf_data = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
