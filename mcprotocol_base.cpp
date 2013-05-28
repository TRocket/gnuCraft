#include "mcprotocol_base.h"

namespace MC
{
namespace Protocol
{

// позже в инлайн
size_t SkipBytes(const Buffer& _src, size_t _offset, int _nBytes)
{
	CheckIfEnoughBytesToRead(_src, _offset, _nBytes);
	return _offset + _nBytes;
}


size_t ReadInt8(const Buffer& _src, size_t _offset, int8_t& _dst)
{
	CheckIfEnoughBytesToRead(_src, _offset, sizeof(_dst));
	_dst = _src.data()[_offset];

	return _offset + sizeof(_dst);
}

size_t ReadInt16(const Buffer& _src, size_t _offset, int16_t& _dst)
{
	CheckIfEnoughBytesToRead(_src, _offset, sizeof(_dst));
	memcpy(&_dst, _src.data() + _offset, sizeof(_dst));
	boost::endian::big_to_native(_dst);
	return _offset + sizeof(_dst);
}

size_t ReadInt32(const Buffer& _src, size_t _offset, int32_t& _dst)
{
	CheckIfEnoughBytesToRead(_src, _offset, sizeof(_dst));
	memcpy(&_dst, _src.data() + _offset, sizeof(_dst));
	boost::endian::big_to_native(_dst);
	return _offset + sizeof(_dst);
}

size_t ReadInt64(const Buffer& _src, size_t _offset, int64_t& _dst)
{
	CheckIfEnoughBytesToRead(_src, _offset, sizeof(_dst));
	memcpy(&_dst, _src.data() + _offset, sizeof(_dst));
	boost::endian::big_to_native(_dst);
	return _offset + sizeof(_dst);
}

size_t ReadBool(const Buffer& _src, size_t _offset, bool& _dst)
{
	return ReadInt8(_src, _offset, reinterpret_cast<int8_t&>(_dst));
}


size_t ReadFloat(const Buffer& _src, size_t _offset, float& _dst)
{
	CheckIfEnoughBytesToRead(_src, _offset, sizeof(_dst)); // ?? может быть тут лучше захардкодить
	memcpy(&_dst, _src.data() + _offset, sizeof(_dst));
	boost::endian::big_to_native(reinterpret_cast<int32_t&>(_dst));
	return _offset + sizeof(_dst);
}

size_t ReadDouble(const Buffer& _src, size_t _offset, double& _dst)
{
	CheckIfEnoughBytesToRead(_src, _offset, sizeof(_dst)); // ?? может быть тут лучше захардкодить
	memcpy(&_dst, _src.data() + _offset, sizeof(_dst));
	boost::endian::big_to_native(reinterpret_cast<int64_t&>(_dst));
	return _offset + sizeof(_dst);
}

size_t ReadString16(const Buffer& _src, size_t _offset, std::wstring& _dst)
{
	CheckIfEnoughBytesToRead(_src, _offset, 2);
	int16_t strLen;
	_offset = ReadInt(_src, _offset, strLen);

	CheckIfEnoughBytesToRead(_src, _offset, strLen);

	_dst.clear();
	_dst.reserve(strLen);

	int16_t ch;
	for(int i = 0; i < strLen; ++i)
	{
		_offset = ReadInt(_src, _offset, ch);
		_dst.push_back(ch);
	}

	return _offset;
}

size_t ReadByteArray(const Buffer& _src, size_t _offset, size_t _len, ByteArray& _dst) // на данный момент оба типа в аргументах одинаковые
{
	CheckIfEnoughBytesToRead(_src, _offset, _len);

	_dst.clear();
	_dst.resize(_len);
	std::copy(_src.begin() + _offset, _src.begin() + _offset + _len, _dst.begin());

	return _offset + _len;
}



size_t WriteInt8(Buffer& _dst, size_t _offset, int8_t _src)
{
	if(_offset < 0)
		_offset = _dst.size();

	_dst.insert(_dst.begin() + _offset, _src);

	return _offset + sizeof(_src);
}

size_t WriteInt16(Buffer& _dst, size_t _offset, int16_t _src)
{
	if(_offset < 0)
		_offset = _dst.size();

	boost::endian::native_to_big(_src);
	_dst.insert(_dst.begin() + _offset, reinterpret_cast<uint8_t*>(&_src), reinterpret_cast<uint8_t*>(&_src) + sizeof(_src));

	return _offset + sizeof(_src);
}

size_t WriteInt32(Buffer& _dst, size_t _offset, int32_t _src)
{
	if(_offset < 0)
		_offset = _dst.size();

	boost::endian::native_to_big(_src);
	_dst.insert(_dst.begin() + _offset, reinterpret_cast<uint8_t*>(&_src), reinterpret_cast<uint8_t*>(&_src) + sizeof(_src));

	return _offset + sizeof(_src);
}

size_t WriteInt64(Buffer& _dst, size_t _offset, int64_t _src)
{
	if(_offset < 0)
		_offset = _dst.size();

	boost::endian::native_to_big(_src);
	_dst.insert(_dst.begin() + _offset, reinterpret_cast<uint8_t*>(&_src), reinterpret_cast<uint8_t*>(&_src) + sizeof(_src));

	return _offset + sizeof(_src);
}

size_t WriteBool(Buffer& _dst, size_t _offset, bool _src)
{
	return WriteInt8(_dst, _offset, _src); // ???
}


size_t WriteFloat(Buffer& _dst, size_t _offset, float _src)
{
	int32_t buf;
	memcpy(&buf, &_src, 4);
	return WriteInt(_dst, _offset, buf);
}

size_t WriteDouble(Buffer& _dst, size_t _offset, double _src)
{
	int64_t buf;
	memcpy(&buf, &_src, 8);
	return WriteInt(_dst, _offset, buf);
}

size_t WriteString16(Buffer& _dst, size_t _offset, const std::wstring& _src)
{
	_offset = WriteInt<int16_t>(_dst, _offset, _src.size());
	for(int i = 0; i < _src.size(); ++i)
		_offset = WriteInt(_dst, _offset, static_cast<int16_t>(_src[i]));

	return _offset;
}

size_t WriteByteArray(Buffer& _dst, size_t _offset, const ByteArray& _src)
{
	if(_offset < 0)
		_offset = _dst.size();

	//for(int i = 0; i < _src.size(); ++i)
	_dst.insert(_dst.begin() + _offset, _src.begin(), _src.end());

	return _dst.size();
}


namespace Msg
{

// -------- Реализация методов BaseMessage --------

//Sint8 BaseMessage::getPacketId() const	{ return _pf_packetId; }


void BaseMessage::_pm_checkInit()
{
	if(!_pf_initialized)
		throw Exception_SerializeUninitializedMessage();
}

size_t BaseMessage::_pm_checkPacketId(const Buffer& _src, size_t _offset)
{
	CheckIfEnoughBytesToRead(_src, _offset, 1);

	int8_t pid = _src[_offset];

	if(pid != _pf_packetId)
	{
		std::cerr	<< __FUNCTION__ << ": wrong packet id (" << std::hex << (int32_t) pid
					<< ", " << (int32_t) _pf_packetId << " needed)." << std::dec << std::endl;
		throw Exception_DeserializeWrongPacket();
	}

	return _offset + 1;
}
//
//
//void BaseMessage::_pm_deserializeBool(StreamBuffer& _src, bool&  _dst)
//{
//	_src.get((char&) _dst);
//}
//
//void BaseMessage::_pm_deserializeInt8(StreamBuffer& _src, Sint8& _dst)
//{
//	_src.get((char&) _dst);
//}
//
//void BaseMessage::_pm_deserializeInt16(StreamBuffer& _src, Sint16& _dst)
//{
//	std::vector<Uint8> buf;
//	_pm_readBytesFromStreamBuffer(_src, buf, 2);
//	_dst = SDLNet_Read16(buf.data());
//}
//
//void BaseMessage::_pm_deserializeInt32(StreamBuffer& _src, Sint32& _dst)
//{
//	std::vector<Uint8> buf;
//	_pm_readBytesFromStreamBuffer(_src, buf, 4);
//	_dst = SDLNet_Read32(buf.data());
//}
//
//void BaseMessage::_pm_deserializeInt64(StreamBuffer& _src, Sint64& _dst)
//{
//	std::vector<Uint8> buf;
//	_pm_readBytesFromStreamBuffer(_src, buf, 8);
//
//	if(SDL_BYTEORDER == SDL_LIL_ENDIAN)
//		std::reverse(buf.begin(), buf.end());
//
//	memcpy(&_dst, buf.data(), 8);
//}
//
//
//void BaseMessage::_pm_deserializeFloat(StreamBuffer& _src, float&  _dst)
//{
//	std::vector<Uint8> buf;
//	_pm_readBytesFromStreamBuffer(_src, buf, 4);
//
//	// В яве даже флоаты и даблы отличаются порядком байт, нужно учесть
//	if(SDL_BYTEORDER == SDL_LIL_ENDIAN)
//		std::reverse(buf.begin(), buf.end());
//
//	memcpy(&_dst, buf.data(), 4);
//
//	//_dst = reinterpret_cast<float>(SDLNet_Read32(buf.data()));
//}
//
//void BaseMessage::_pm_deserializeDouble(StreamBuffer& _src, double& _dst)
//{
//	std::vector<Uint8> buf;
//	_pm_readBytesFromStreamBuffer(_src, buf, 8);
//
//	// В яве даже флоаты и даблы отличаются порядком байт, нужно учесть
//	if(SDL_BYTEORDER == SDL_LIL_ENDIAN)
//		std::reverse(buf.begin(), buf.end());
//
//	memcpy(&_dst, buf.data(), 8);
//}
//
//
//void BaseMessage::_pm_deserializeWstring(StreamBuffer& _src, std::wstring& _dst)
//{
//	std::vector<Uint8> buf;
//
//	// Получение длины строки (int16)
//	Sint16 strLen;
//	_pm_deserializeInt16(_src, strLen);
//
//	int len2 = (Uint16) strLen;
//
//	// Получение строки.
//	_pm_readBytesFromStreamBuffer(_src, buf, len2 * 2);
//	_dst.reserve(len2); // уточнить насчёт резервирования и необходимости места под \0
//	Sint16 ch;
//
//	for(int i = 0; i < len2; ++i)
//	{
//		//if(i % 1000 == 0)
//		//	std::cout << i << std::endl;
//
//		//_pm_deserializeInt16(buf.data() + i * 2, ch);
//		ch = SDLNet_Read16(buf.data() + i * 2);
//		_dst.push_back(ch);
//	}
//}
//
//
//// Десериализация байтового массива. Его длину нужно забирать отдельно, потому что она бывает в разных местах.
//// ВНЕЗАПНО нашлась функция чтения в вектор, так что эта пока послужит обёрткой.
//void BaseMessage::_pm_deserializeByteArray(StreamBuffer& _src, std::vector<Uint8>& _dst, int _size)
//{
//	_pm_readBytesFromStreamBuffer(_src, _dst, _size);
//}


} // namespace Msg
} // namespace Protocol
} // namespace MC