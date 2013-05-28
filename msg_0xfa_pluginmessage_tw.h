#ifndef _MSG_0XFA_PLUGINMESSAGE_TW_H_
#define _MSG_0XFA_PLUGINMESSAGE_TW_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class PluginMessage : public BaseMessage
{
public:
	PluginMessage();
	PluginMessage(const String16& _channel, const ByteArray& _data);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getChannel() const;
	const ByteArray& getData() const;

	void setChannel(const String16& _val);
	void setData(const ByteArray& _val);


private:
	String16 _pf_channel;
	ByteArray _pf_data;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XFA_PLUGINMESSAGE_TW_H_