#ifndef _METADATA_H_
#define _METADATA_H_

#include "mcprotocol_base.h"
#include "slotdata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class Metadata : public BaseMessage
{
public:
	Metadata();
	Metadata(int8_t _item);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getItem() const;

	void setItem(int8_t _val);


private:
	int8_t _pf_item;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG__METADATA__H_