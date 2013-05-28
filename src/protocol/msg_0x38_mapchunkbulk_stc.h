#ifndef _MSG_0X38_MAPCHUNKBULK_STC_H_
#define _MSG_0X38_MAPCHUNKBULK_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class MapChunkBulk : public BaseMessage
{
public:
	MapChunkBulk();
	MapChunkBulk(int16_t _chunkColumnCount, int32_t _dataLength, bool _skyLightSent, const ByteArray& _chunkData, const ByteArray& _metaInfo);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int16_t getChunkColumnCount() const;
	int32_t getDataLength() const;
	bool getSkyLightSent() const;
	const ByteArray& getChunkData() const;
	const ByteArray& getMetaInfo() const;

	void setChunkColumnCount(int16_t _val);
	void setDataLength(int32_t _val);
	void setSkyLightSent(bool _val);
	void setChunkData(const ByteArray& _val);
	void setMetaInfo(const ByteArray& _val);


private:
	int16_t _pf_chunkColumnCount;
	int32_t _pf_dataLength;
	bool _pf_skyLightSent;
	ByteArray _pf_chunkData;
	ByteArray _pf_metaInfo;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X38_MAPCHUNKBULK_STC_H_