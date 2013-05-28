#include "metadata.h"

namespace MC
{
namespace Protocol
{
namespace Msg
{

Metadata::Metadata()
{
	//_pf_packetId = static_cast<int8_t>();
	_pf_initialized = false;
}

Metadata::Metadata(int8_t _item)
	:	_pf_item(_item)
{
	//_pf_packetId = static_cast<int8_t>();
	_pf_initialized = true;
}


size_t Metadata::serialize(Buffer& _dst, size_t _offset)
{
	throw "NYI";
	return 0;

	/*_pm_checkInit();
	_dst.clear();

	_pm_serializeInt8(_pf_packetId, _dst);
	_pm_serializeInt8(_pf_item, _dst);*/
}

size_t Metadata::deserialize(const Buffer& _src, size_t _offset)
{
	//_pm_checkPacketId(_src);

	//std::cout << "Warning! Metadata is skipped!" << std::endl;

	while(1)
	{
		_offset = ReadInt8(_src, _offset, _pf_item);
		if (_pf_item == 0x7F)
			break;

		int8_t index = _pf_item & 0x1F;
		int8_t type = _pf_item >> 5;

		switch(type)
		{
		case 0: // int8
			_offset = SkipBytes(_src, _offset, 1);
			break;

		case 1: // int16
			_offset = SkipBytes(_src, _offset, 2);
			break;

		case 2: // int32
			_offset = SkipBytes(_src, _offset, 4);
			break;

		case 3: // float
			_offset = SkipBytes(_src, _offset, 4);
			break;

		case 4: // wstring
			{
			String16 dummy;
			_offset = ReadString16(_src, _offset, dummy);			
			break;
			}

		case 5: // slot
			{
			_offset = SkipBytes(_src, _offset, 1);
			_offset = SlotData().deserialize(_src, _offset);
			break;
			}

		case 6: // 3x int32
			_offset = SkipBytes(_src, _offset, 12);
			break;
		}
    }

	_pf_initialized = true;

	return _offset;
}

int8_t Metadata::getItem() const { return _pf_item; }

void Metadata::setItem(int8_t _val) { _pf_item = _val; }

} // namespace Msg
} // namespace Protocol
} // namespace MC
