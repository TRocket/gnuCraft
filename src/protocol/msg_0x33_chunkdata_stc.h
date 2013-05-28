#ifndef _MSG_0X33_CHUNKDATA_STC_H_
#define _MSG_0X33_CHUNKDATA_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ChunkData : public BaseMessage
{
public:
	ChunkData();
	ChunkData(int32_t _chunkX, int32_t _chunkZ, bool _groundUpContiguous, int16_t _primaryBitMap, int16_t _addBitMap, int32_t _compressedSize, const ByteArray& _compressedData);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getChunkX() const;
	int32_t getChunkZ() const;
	bool getGroundUpContiguous() const;
	int16_t getPrimaryBitMap() const;
	int16_t getAddBitMap() const;
	int32_t getCompressedSize() const;
	const ByteArray& getCompressedData() const;

	void setChunkX(int32_t _val);
	void setChunkZ(int32_t _val);
	void setGroundUpContiguous(bool _val);
	void setPrimaryBitMap(int16_t _val);
	void setAddBitMap(int16_t _val);
	void setCompressedSize(int32_t _val);
	void setCompressedData(const ByteArray& _val);


private:
	int32_t _pf_chunkX;
	int32_t _pf_chunkZ;
	bool _pf_groundUpContiguous;
	int16_t _pf_primaryBitMap;
	int16_t _pf_addBitMap;
	int32_t _pf_compressedSize;
	ByteArray _pf_compressedData;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X33_CHUNKDATA_STC_H_