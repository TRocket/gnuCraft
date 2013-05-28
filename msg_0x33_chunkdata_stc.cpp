#include "msg_0x33_chunkdata_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ChunkData::ChunkData()
{
	_pf_packetId = static_cast<int8_t>(0x33);
	_pf_initialized = false;
}

ChunkData::ChunkData(int32_t _chunkX, int32_t _chunkZ, bool _groundUpContiguous, int16_t _primaryBitMap, int16_t _addBitMap, int32_t _compressedSize, const ByteArray& _compressedData)
	:	_pf_chunkX(_chunkX)
	,	_pf_chunkZ(_chunkZ)
	,	_pf_groundUpContiguous(_groundUpContiguous)
	,	_pf_primaryBitMap(_primaryBitMap)
	,	_pf_addBitMap(_addBitMap)
	,	_pf_compressedSize(_compressedSize)
	,	_pf_compressedData(_compressedData)
{
	_pf_packetId = static_cast<int8_t>(0x33);
	_pf_initialized = true;
}


size_t ChunkData::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_chunkX);
	_offset = WriteInt32(_dst, _offset, _pf_chunkZ);
	_offset = WriteBool(_dst, _offset, _pf_groundUpContiguous);
	_offset = WriteInt16(_dst, _offset, _pf_primaryBitMap);
	_offset = WriteInt16(_dst, _offset, _pf_addBitMap);
	_offset = WriteInt32(_dst, _offset, _pf_compressedSize);
	_offset = WriteByteArray(_dst, _offset, _pf_compressedData);


	return _offset;
}

size_t ChunkData::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_chunkX);
	_offset = ReadInt32(_src, _offset, _pf_chunkZ);
	_offset = ReadBool(_src, _offset, _pf_groundUpContiguous);
	_offset = ReadInt16(_src, _offset, _pf_primaryBitMap);
	_offset = ReadInt16(_src, _offset, _pf_addBitMap);
	_offset = ReadInt32(_src, _offset, _pf_compressedSize);
	_offset = ReadByteArray(_src, _offset, _pf_compressedSize, _pf_compressedData);
	_pf_initialized = true;
	return _offset;
}

int32_t ChunkData::getChunkX() const { return _pf_chunkX; }
int32_t ChunkData::getChunkZ() const { return _pf_chunkZ; }
bool ChunkData::getGroundUpContiguous() const { return _pf_groundUpContiguous; }
int16_t ChunkData::getPrimaryBitMap() const { return _pf_primaryBitMap; }
int16_t ChunkData::getAddBitMap() const { return _pf_addBitMap; }
int32_t ChunkData::getCompressedSize() const { return _pf_compressedSize; }
const ByteArray& ChunkData::getCompressedData() const { return _pf_compressedData; }

void ChunkData::setChunkX(int32_t _val) { _pf_chunkX = _val; }
void ChunkData::setChunkZ(int32_t _val) { _pf_chunkZ = _val; }
void ChunkData::setGroundUpContiguous(bool _val) { _pf_groundUpContiguous = _val; }
void ChunkData::setPrimaryBitMap(int16_t _val) { _pf_primaryBitMap = _val; }
void ChunkData::setAddBitMap(int16_t _val) { _pf_addBitMap = _val; }
void ChunkData::setCompressedSize(int32_t _val) { _pf_compressedSize = _val; }
void ChunkData::setCompressedData(const ByteArray& _val) { _pf_compressedData = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
