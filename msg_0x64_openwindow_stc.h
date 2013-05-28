#ifndef _MSG_0X64_OPENWINDOW_STC_H_
#define _MSG_0X64_OPENWINDOW_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class OpenWindow : public BaseMessage
{
public:
	OpenWindow();
	OpenWindow(int8_t _windowId, int8_t _inventoryType, const String16& _windowTitle, int8_t _numOfSlots, bool _useProvidedWindowTitle);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	int8_t getWindowId() const;
	int8_t getInventoryType() const;
	const String16& getWindowTitle() const;
	int8_t getNumOfSlots() const;
	bool getUseProvidedWindowTitle() const;

	void setWindowId(int8_t _val);
	void setInventoryType(int8_t _val);
	void setWindowTitle(const String16& _val);
	void setNumOfSlots(int8_t _val);
	void setUseProvidedWindowTitle(bool _val);


private:
	int8_t _pf_windowId;
	int8_t _pf_inventoryType;
	String16 _pf_windowTitle;
	int8_t _pf_numOfSlots;
	bool _pf_useProvidedWindowTitle;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X64_OPENWINDOW_STC_H_