#include "msg_0xd1_teams_stc.h"


namespace MC
{
namespace Protocol
{
namespace Msg
{

Teams::Teams()
{
	_pf_packetId = 0xD1;
	_pf_initialized = false;
}


size_t Teams::serialize(Buffer& _dst, size_t _offset)
{
	std::cout << __FUNCTION__ << " NYI!" << std::endl;
	throw "NYI";

	return -1;
}

size_t Teams::deserialize(const Buffer& _src, size_t _offset)
{
	_offset = _pm_checkPacketId(_src, _offset);

	_offset = ReadString16(_src, _offset, _pf_teamName);

	_offset = ReadInt8(_src, _offset, _pf_mode);
	//std::cout << "Mode: " << (int) _pf_mode << std::endl;

	if(_pf_mode == 0 || _pf_mode == 2)
	{
		_offset = ReadString16(_src, _offset, _pf_teamDisplayName);
		_offset = ReadString16(_src, _offset, _pf_teamPrefix);
		_offset = ReadString16(_src, _offset, _pf_teamSuffix);
		_offset = ReadInt8(_src, _offset, _pf_friendlyFire);
	}
	if(_pf_mode == 0 || _pf_mode == 3 || _pf_mode == 4)
	{	
		_offset = ReadInt16(_src, _offset, _pf_playerCount);

		std::wstring dummyPlayer;
		for(int i = 0; i < _pf_playerCount; ++i)
		{
			_offset = ReadString16(_src, _offset, dummyPlayer);
		}
		//Players;
	}

	return _offset;
}

} // namespace MC
} // namespace Protocol
} // namespace Msg