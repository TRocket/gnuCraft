#ifndef _MSG_0X16_COLLECTITEM_STC_H_
#define _MSG_0X16_COLLECTITEM_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class CollectItem : public BaseMessage
{
public:
	CollectItem();
	CollectItem(int32_t _collectedEID, int32_t _collectorEID);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getCollectedEID() const;
	int32_t getCollectorEID() const;

	void setCollectedEID(int32_t _val);
	void setCollectorEID(int32_t _val);


private:
	int32_t _pf_collectedEID;
	int32_t _pf_collectorEID;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X16_COLLECTITEM_STC_H_