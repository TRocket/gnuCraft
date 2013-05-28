#ifndef _MSG_0XCF_UPDATESCORE_STC_H_
#define _MSG_0XCF_UPDATESCORE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class UpdateScore : public BaseMessage
{
public:
	UpdateScore();
	UpdateScore(const String16& _itemName, int8_t _update_remove, const String16& _scoreName, int32_t _value);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getItemName() const;
	int8_t getUpdate_remove() const;
	const String16& getScoreName() const;
	int32_t getValue() const;

	void setItemName(const String16& _val);
	void setUpdate_remove(int8_t _val);
	void setScoreName(const String16& _val);
	void setValue(int32_t _val);


private:
	String16 _pf_itemName;
	int8_t _pf_update_remove;
	String16 _pf_scoreName;
	int32_t _pf_value;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XCF_UPDATESCORE_STC_H_