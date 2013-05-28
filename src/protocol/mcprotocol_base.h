#ifndef _MCPROTOCOL_BASE_H_
#define _MCPROTOCOL_BASE_H_

 #include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <boost/endian/conversion.hpp>
//#include <sdl/SDL_stdinc.h> // �� ��������� ������ "�����������" ������ �� typedef
//#include <sdl/SDL_net.h>
//#include <sdl/SDL_endian.h>

namespace MC
{
namespace Protocol
{

typedef std::vector<uint8_t>	ByteArray;
typedef std::vector<uint8_t>	Buffer;
typedef std::wstring			String16;

const int VERSION = 61; // 1.5.2

//class SlotData; // ���������� ����������� ��� ��������� dependency hell


// ����������� ������� ������������/��������������

class Exception_NotEnoughDataToRead {};

// ������� ����������, ���� ������������
inline void CheckIfEnoughBytesToRead(const Buffer& _src, size_t _offset, int _neededNBytes);

size_t SkipBytes(const Buffer& _src, size_t _offset, int _nBytes);

template<class T> size_t ReadInt(const Buffer& _src, size_t _offset, T& _dst);
size_t ReadInt8(const Buffer& _src, size_t _offset, int8_t& _dst);
size_t ReadInt16(const Buffer& _src, size_t _offset, int16_t& _dst);
size_t ReadInt32(const Buffer& _src, size_t _offset, int32_t& _dst);
size_t ReadInt64(const Buffer& _src, size_t _offset, int64_t& _dst);
size_t ReadBool(const Buffer& _src, size_t _offset, bool& _dst);

size_t ReadFloat(const Buffer& _src, size_t _offset, float& _dst);
size_t ReadDouble(const Buffer& _src, size_t _offset, double& _dst);
size_t ReadString16(const Buffer& _src, size_t _offset, std::wstring& _dst);
size_t ReadByteArray(const Buffer& _src, size_t _offset, size_t _len, ByteArray& _dst); // �� ������ ������ ��� ���� � ���������� ����������


template<class T> size_t WriteInt(Buffer& _dst, size_t _offset, T _src);
size_t WriteInt8(Buffer& _dst, size_t _offset, int8_t _src);
size_t WriteInt16(Buffer& _dst, size_t _offset, int16_t _src);
size_t WriteInt32(Buffer& _dst, size_t _offset, int32_t _src);
size_t WriteInt64(Buffer& _dst, size_t _offset, int64_t _src);
size_t WriteBool(Buffer& _dst, size_t _offset, bool _src);

size_t WriteFloat(Buffer& _dst, size_t _offset, float _src);
size_t WriteDouble(Buffer& _dst, size_t _offset, double _src);
size_t WriteString16(Buffer& _dst, size_t _offset, const std::wstring& _src);
size_t WriteByteArray(Buffer& _dst, size_t _offset, const ByteArray& _src);

//size_t WriteSlotData(Buffer& _dst, size_t _offset, const SlotData& _src);


namespace Msg
{

// ������������� ID ������. ������������ � ������������� �� ���������.
// �� ������ ��������� 61 (1.5.2) ������ 0xF0 �� ����������. ��������, ����� ���������.
const int8_t SENCELESS_PACKET_ID = 0xF0;


// ������� ����� ���������
class BaseMessage
{
public:
	//BaseMessage() { _pf_initialized = false;}

	virtual size_t serialize(Buffer& _src, size_t _offset) = 0;
	virtual size_t deserialize(const Buffer& _src, size_t _offset) = 0;

	int8_t getPacketId() const;

	// ����������

	// ������� ������������� �������������������� ���������
	class Exception_SerializeUninitializedMessage {};
	// ������� ��������������� ������� ���������
	class Exception_DeserializeNullPtr {};
	// ������� ��������������� ��������� �� ��� �������
	class Exception_DeserializeWrongPacket {};
	
		
protected:
	int8_t _pf_packetId;  // ������ ���� const
	bool _pf_initialized;
	//const Sint8 _pf_PACKET_ID;

	void _pm_checkInit();
	size_t _pm_checkPacketId(const Buffer& _src, size_t _offset);

};


} // namespace Msg
} // namespace Protocol
} // namespace MC


// ���������� ������� ��������
void MC::Protocol::CheckIfEnoughBytesToRead(const Buffer& _src, size_t _offset, int _neededNBytes)
{
	if(_src.size() - _offset < _neededNBytes)
		throw Exception_NotEnoughDataToRead();
}

template<typename T>
size_t MC::Protocol::ReadInt(const Buffer& _src, size_t _offset, T& _dst)
{
	CheckIfEnoughBytesToRead(_src, _offset, sizeof(T));
	memcpy(&_dst, _src.data() + _offset, sizeof(T));
	if(sizeof(T) > 1)
		boost::endian::big_to_native(_dst);
	return _offset + sizeof(T);
}

template<class T>
size_t MC::Protocol::WriteInt(Buffer& _dst, size_t _offset, T _src)
{
	if(_offset < 0)
		_offset = _dst.size();

	boost::endian::native_to_big(_src);
	_dst.insert(_dst.begin() + _offset, reinterpret_cast<uint8_t*>(&_src), reinterpret_cast<uint8_t*>(&_src) + sizeof(T));

	return _offset + sizeof(T);
}



#endif // _MCPROTOCOL_BASE_H_
