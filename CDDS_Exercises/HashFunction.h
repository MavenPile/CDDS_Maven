#pragma once

#include <functional>

namespace HashFunction {

	typedef std::function<unsigned int(const char*, unsigned int)> HashFunc; 

	unsigned int badHash(const char* data, unsigned int length);

	//	METHODS



	static HashFunc Default = badHash;
}