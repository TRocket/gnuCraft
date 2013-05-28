#include "msg_0x38_mapchunkbulk_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

MapChunkBulk::MapChunkBulk()
{
	_pf_packetId = static_cast<int8_t>(0x38);
	_pf_initialized = false;
}

MapChunkBulk::MapChunkBulk(int16_t _chunkColumnCount, int32_t _dataLength, bool _skyLightSent, const ByteArray& _chunkData, const ByteArray& _metaInfo)
	:	_pf_chunkColumnCount(_chunkColumnCount)
	,	_pf_dataLength(_dataLength)
	,	_pf_skyLightSent(_skyLightSent)
	,	_pf_chunkData(_chunkData)
	,	_pf_metaInfo(_metaInfo)
{
	_pf_packetId = static_cast<int8_t>(0x38);
	_pf_initialized = true;
}


size_t MapChunkBulk::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt16(_dst, _offset, _pf_chunkColumnCount);
	_offset = WriteInt32(_dst, _offset, _pf_dataLength);
	_offset = WriteBool(_dst, _offset, _pf_skyLightSent);
	_offset = WriteByteArray(_dst, _offset, _pf_chunkData);
	_offset = WriteByteArray(_dst, _offset, _pf_metaInfo);


	return _offset;
}

size_t MapChunkBulk::deserialize(const Buffer& _src, size_t _offset)
{
	//size_t off1 = _offset;

	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt16(_src, _offset, _pf_chunkColumnCount);
	_offset = ReadInt32(_src, _offset, _pf_dataLength);
	_offset = ReadBool(_src, _offset, _pf_skyLightSent);
	_offset = ReadByteArray(_src, _offset, _pf_dataLength, _pf_chunkData);
	_offset = ReadByteArray(_src, _offset, _pf_chunkColumnCount * 12, _pf_metaInfo);
	_pf_initialized = true;

	//std::cout << "==== 0x38: " << _offset - off1 << " bytes read ====" << std::endl;

	return _offset;
}

int16_t MapChunkBulk::getChunkColumnCount() const { return _pf_chunkColumnCount; }
int32_t MapChunkBulk::getDataLength() const { return _pf_dataLength; }
bool MapChunkBulk::getSkyLightSent() const { return _pf_skyLightSent; }
const ByteArray& MapChunkBulk::getChunkData() const { return _pf_chunkData; }
const ByteArray& MapChunkBulk::getMetaInfo() const { return _pf_metaInfo; }

void MapChunkBulk::setChunkColumnCount(int16_t _val) { _pf_chunkColumnCount = _val; }
void MapChunkBulk::setDataLength(int32_t _val) { _pf_dataLength = _val; }
void MapChunkBulk::setSkyLightSent(bool _val) { _pf_skyLightSent = _val; }
void MapChunkBulk::setChunkData(const ByteArray& _val) { _pf_chunkData = _val; }
void MapChunkBulk::setMetaInfo(const ByteArray& _val) { _pf_metaInfo = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
