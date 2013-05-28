#include "msg_0x16_collectitem_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

CollectItem::CollectItem()
{
	_pf_packetId = static_cast<int8_t>(0x16);
	_pf_initialized = false;
}

CollectItem::CollectItem(int32_t _collectedEID, int32_t _collectorEID)
	:	_pf_collectedEID(_collectedEID)
	,	_pf_collectorEID(_collectorEID)
{
	_pf_packetId = static_cast<int8_t>(0x16);
	_pf_initialized = true;
}


size_t CollectItem::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt32(_dst, _offset, _pf_collectedEID);
	_offset = WriteInt32(_dst, _offset, _pf_collectorEID);


	return _offset;
}

size_t CollectItem::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt32(_src, _offset, _pf_collectedEID);
	_offset = ReadInt32(_src, _offset, _pf_collectorEID);
	_pf_initialized = true;
	return _offset;
}

int32_t CollectItem::getCollectedEID() const { return _pf_collectedEID; }
int32_t CollectItem::getCollectorEID() const { return _pf_collectorEID; }

void CollectItem::setCollectedEID(int32_t _val) { _pf_collectedEID = _val; }
void CollectItem::setCollectorEID(int32_t _val) { _pf_collectorEID = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
