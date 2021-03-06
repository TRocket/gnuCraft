#ifndef _MSG_0X03_CHATMESSAGE_TW_H_
#define _MSG_0X03_CHATMESSAGE_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ChatMessage : public BaseMessage
{
public:
	ChatMessage();
	ChatMessage(const String16& _text);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getText() const;

	void setText(const String16& _val);


private:
	String16 _pf_text;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0X03_CHATMESSAGE_TW_H_