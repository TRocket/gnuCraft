#include "msg_0xce_scoreboardobjective_stc.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

ScoreboardObjective::ScoreboardObjective()
{
	_pf_packetId = static_cast<int8_t>(0xCE);
	_pf_initialized = false;
}

ScoreboardObjective::ScoreboardObjective(const String16& _objectiveName, const String16& _objectiveValue, int8_t _action)
	:	_pf_objectiveName(_objectiveName)
	,	_pf_objectiveValue(_objectiveValue)
	,	_pf_action(_action)
{
	_pf_packetId = static_cast<int8_t>(0xCE);
	_pf_initialized = true;
}


size_t ScoreboardObjective::serialize(Buffer& _dst, size_t _offset)
{
	_pm_checkInit();
	if(_offset == 0) _dst.clear();

	_offset = WriteInt8(_dst, _offset, _pf_packetId);
	_offset = WriteString16(_dst, _offset, _pf_objectiveName);
	_offset = WriteString16(_dst, _offset, _pf_objectiveValue);
	_offset = WriteInt8(_dst, _offset, _pf_action);


	return _offset;
}

size_t ScoreboardObjective::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_objectiveName);
	_offset = ReadString16(_src, _offset, _pf_objectiveValue);
	_offset = ReadInt8(_src, _offset, _pf_action);
	_pf_initialized = true;
	return _offset;
}

const String16& ScoreboardObjective::getObjectiveName() const { return _pf_objectiveName; }
const String16& ScoreboardObjective::getObjectiveValue() const { return _pf_objectiveValue; }
int8_t ScoreboardObjective::getAction() const { return _pf_action; }

void ScoreboardObjective::setObjectiveName(const String16& _val) { _pf_objectiveName = _val; }
void ScoreboardObjective::setObjectiveValue(const String16& _val) { _pf_objectiveValue = _val; }
void ScoreboardObjective::setAction(int8_t _val) { _pf_action = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
