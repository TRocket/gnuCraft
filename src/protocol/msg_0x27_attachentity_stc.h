#ifndef _MSG_0X27_ATTACHENTITY_STC_H_
#define _MSG_0X27_ATTACHENTITY_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class AttachEntity : public BaseMessage
{
public:
	AttachEntity();
	AttachEntity(int32_t _entityId, int32_t _vehicleId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int32_t getEntityId() const;
	int32_t getVehicleId() const;

	void setEntityId(int32_t _val);
	void setVehicleId(int32_t _val);


private:
	int32_t _pf_entityId;
	int32_t _pf_vehicleId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X27_ATTACHENTITY_STC_H_