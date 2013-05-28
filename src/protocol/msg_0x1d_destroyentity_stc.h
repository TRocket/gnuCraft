#ifndef _MSG_0X1D_DESTROYENTITY_STC_H_
#define _MSG_0X1D_DESTROYENTITY_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class DestroyEntity : public BaseMessage
{
public:
	DestroyEntity();
	DestroyEntity(int8_t _entityCount, const std::vector<int32_t>& _entityIds);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getEntityCount() const;

	void setEntityCount(int8_t _val);


private:
	int8_t _pf_entityCount;
	std::vector<int32_t> _pf_entityIds;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X1D_DESTROYENTITY_STC_H_