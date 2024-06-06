#pragma once

#include <functional>

namespace HashFunction {

	typedef std::function<unsigned int(const char*, unsigned int)> HashFunc; 

	unsigned int BadHash(const char* data, unsigned int length);

	//	METHODS

	unsigned int BasicHash(unsigned char* data, unsigned int length);

	unsigned int BKDRHash(unsigned char* data, unsigned int length);

	unsigned int ELFHash(unsigned char* data, unsigned int length);

	static HashFunc Default = BadHash;
}