#ifndef _MSG_0XCC_CLIENTSETTINGS_CTS_H_
#define _MSG_0XCC_CLIENTSETTINGS_CTS_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ClientSettings : public BaseMessage
{
public:
	ClientSettings();
	ClientSettings(const String16& _locale, int8_t _viewDistance, int8_t _chatFlags, int8_t _difficulty, bool _showCape);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getLocale() const;
	int8_t getViewDistance() const;
	int8_t getChatFlags() const;
	int8_t getDifficulty() const;
	bool getShowCape() const;

	void setLocale(const String16& _val);
	void setViewDistance(int8_t _val);
	void setChatFlags(int8_t _val);
	void setDifficulty(int8_t _val);
	void setShowCape(bool _val);


private:
	String16 _pf_locale;
	int8_t _pf_viewDistance;
	int8_t _pf_chatFlags;
	int8_t _pf_difficulty;
	bool _pf_showCape;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XCC_CLIENTSETTINGS_CTS_H_