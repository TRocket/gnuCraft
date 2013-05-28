#ifndef _MSG_0X28_ENTITYMETADATA_STC_H_
#define _MSG_0X28_ENTITYMETADATA_STC_H_

#include "mcprotocol_base.h"
#include "metadata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class EntityMetadata : public BaseMessage
{
public:
	EntityMetadata();
	EntityMetadata(int32_t _entityId, Metadata _metadata);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	Metadata getMetadata() const;

	void setEntityId(int32_t _val);
	void setMetadata(Metadata _val);


private:
	int32_t _pf_entityId;
	Metadata _pf_metadata;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X28_ENTITYMETADATA_STC_H_