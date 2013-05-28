#include "msg_0x6a_confirmtransaction_tw.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ConfirmTransaction::ConfirmTransaction()
{
	_pf_packetId = static_cast<int8_t>(0x6A);
	_pf_initialized = false;
}

ConfirmTransaction::ConfirmTransaction(int8_t _windowId, int16_t _actionNumber, bool _accepted)
	:	_pf_windowId(_windowId)
	,	_pf_actionNumber(_actionNumber)
	,	_pf_accepted(_accepted)
{
	_pf_packetId = static_cast<int8_t>(0x6A);
	_pf_initialized = true;
}


size_t ConfirmTransaction::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteInt8(_dst, _offset, _pf_windowId);
	_offset = WriteInt16(_dst, _offset, _pf_actionNumber);
	_offset = WriteBool(_dst, _offset, _pf_accepted);


	return _offset;
}

size_t ConfirmTransaction::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadInt8(_src, _offset, _pf_windowId);
	_offset = ReadInt16(_src, _offset, _pf_actionNumber);
	_offset = ReadBool(_src, _offset, _pf_accepted);
	_pf_initialized = true;
	return _offset;
}

int8_t ConfirmTransaction::getWindowId() const { return _pf_windowId; }
int16_t ConfirmTransaction::getActionNumber() const { return _pf_actionNumber; }
bool ConfirmTransaction::getAccepted() const { return _pf_accepted; }

void ConfirmTransaction::setWindowId(int8_t _val) { _pf_windowId = _val; }
void ConfirmTransaction::setActionNumber(int16_t _val) { _pf_actionNumber = _val; }
void ConfirmTransaction::setAccepted(bool _val) { _pf_accepted = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
