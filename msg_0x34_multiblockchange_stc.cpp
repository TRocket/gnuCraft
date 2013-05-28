#include "msg_0x34_multiblockchange_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

MultiBlockChange::MultiBlockChange()
{
	_pf_packetId = static_cast<int8_t>(0x34);
	_pf_initialized = false;
}

MultiBlockChange::MultiBlockChange(int32_t _chunkX, int32_t _chunkZ, int16_t _recordCount, int32_t _dataLength, const ByteArray& _data)
	:	_pf_chunkX(_chunkX)
	,	_pf_chunkZ(_chunkZ)
	,	_pf_recordCount(_recordCount)
	,	_pf_dataLength(_dataLength)
	,	_pf_data(_data)
{
	_pf_packetId = static_cast<int8_t>(0x34);
	_pf_initialized = true;
}


size_t MultiBlockChange::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_chunkX);
	_offset = WriteInt32(_dst, _offset, _pf_chunkZ);
	_offset = WriteInt16(_dst, _offset, _pf_recordCount);
	_offset = WriteInt32(_dst, _offset, _pf_dataLength);
	_offset = WriteByteArray(_dst, _offset, _pf_data);


	return _offset;
}

size_t MultiBlockChange::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_chunkX);
	_offset = ReadInt32(_src, _offset, _pf_chunkZ);
	_offset = ReadInt16(_src, _offset, _pf_recordCount);
	_offset = ReadInt32(_src, _offset, _pf_dataLength);
	_offset = ReadByteArray(_src, _offset, _pf_dataLength, _pf_data);

	_pf_initialized = true;
	return _offset;
}

int32_t MultiBlockChange::getChunkX() const { return _pf_chunkX; }
int32_t MultiBlockChange::getChunkZ() const { return _pf_chunkZ; }
int16_t MultiBlockChange::getRecordCount() const { return _pf_recordCount; }
int32_t MultiBlockChange::getDataLength() const { return _pf_dataLength; }
const ByteArray& MultiBlockChange::getData() const { return _pf_data; }

void MultiBlockChange::setChunkX(int32_t _val) { _pf_chunkX = _val; }
void MultiBlockChange::setChunkZ(int32_t _val) { _pf_chunkZ = _val; }
void MultiBlockChange::setRecordCount(int16_t _val) { _pf_recordCount = _val; }
void MultiBlockChange::setDataLength(int32_t _val) { _pf_dataLength = _val; }
void MultiBlockChange::setData(const ByteArray& _val) { _pf_data = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
