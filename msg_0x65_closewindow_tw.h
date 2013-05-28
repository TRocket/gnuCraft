#ifndef _MSG_0X65_CLOSEWINDOW_TW_H_
#define _MSG_0X65_CLOSEWINDOW_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class CloseWIndow : public BaseMessage
{
public:
	CloseWIndow();
	CloseWIndow(int8_t _windowId);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getWindowId() const;

	void setWindowId(int8_t _val);


private:
	int8_t _pf_windowId;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X65_CLOSEWINDOW_TW_H_