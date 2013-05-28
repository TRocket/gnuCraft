#ifndef _MSG_0XCE_SCOREBOARDOBJECTIVE_STC_H_
#define _MSG_0XCE_SCOREBOARDOBJECTIVE_STC_H_

#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

class ScoreboardObjective : public BaseMessage
{
public:
	ScoreboardObjective();
	ScoreboardObjective(const String16& _objectiveName, const String16& _objectiveValue, int8_t _action);

	size_t serialize(Buffer& _dst, size_t _offset);
	size_t deserialize(const Buffer& _src, size_t _offset);

	const String16& getObjectiveName() const;
	const String16& getObjectiveValue() const;
	int8_t getAction() const;

	void setObjectiveName(const String16& _val);
	void setObjectiveValue(const String16& _val);
	void setAction(int8_t _val);


private:
	String16 _pf_objectiveName;
	String16 _pf_objectiveValue;
	int8_t _pf_action;
};

} // namespace Msg
} // namespace Protocol
} // namespace MC

#endif // _MSG_0XCE_SCOREBOARDOBJECTIVE_STC_H_