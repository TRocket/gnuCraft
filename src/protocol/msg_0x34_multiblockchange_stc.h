#ifndef _MSG_0X34_MULTIBLOCKCHANGE_STC_H_
#define _MSG_0X34_MULTIBLOCKCHANGE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class MultiBlockChange : public BaseMessage
{
public:
	MultiBlockChange();
	MultiBlockChange(int32_t _chunkX, int32_t _chunkZ, int16_t _recordCount, int32_t _dataLength, const ByteArray& _data);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getChunkX() const;
	int32_t getChunkZ() const;
	int16_t getRecordCount() const;
	int32_t getDataLength() const;
	const ByteArray& getData() const;

	void setChunkX(int32_t _val);
	void setChunkZ(int32_t _val);
	void setRecordCount(int16_t _val);
	void setDataLength(int32_t _val);
	void setData(const ByteArray& _val);


private:
	int32_t _pf_chunkX;
	int32_t _pf_chunkZ;
	int16_t _pf_recordCount;
	int32_t _pf_dataLength;
	ByteArray _pf_data;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X34_MULTIBLOCKCHANGE_STC_H_