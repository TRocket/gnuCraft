#ifndef _MSG_0X6A_CONFIRMTRANSACTION_TW_H_
#define _MSG_0X6A_CONFIRMTRANSACTION_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ConfirmTransaction : public BaseMessage
{
public:
	ConfirmTransaction();
	ConfirmTransaction(int8_t _windowId, int16_t _actionNumber, bool _accepted);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getWindowId() const;
	int16_t getActionNumber() const;
	bool getAccepted() const;

	void setWindowId(int8_t _val);
	void setActionNumber(int16_t _val);
	void setAccepted(bool _val);


private:
	int8_t _pf_windowId;
	int16_t _pf_actionNumber;
	bool _pf_accepted;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X6A_CONFIRMTRANSACTION_TW_H_