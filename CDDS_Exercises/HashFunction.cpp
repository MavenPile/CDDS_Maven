#include "HashFunction.h"

namespace HashFunction {

	unsigned int HashFunction::BadHash(const char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; i++) {
			hash += data[i];
		}

		return hash;
	}

	unsigned int BasicHash(unsigned char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; i++)
		{
			hash += data[i];
		}

		return hash;
	}

	unsigned int BKDRHash(unsigned char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; i++)
		{
			hash = (hash * 1313) + data[i];
		}

		return (hash & 0x7FFFFFFF);
	}

	unsigned int ELFHash(unsigned char* data, unsigned int length)
	{
		unsigned int hash = 0, x = 0;

		for (unsigned int i = 0; i < length; i++)
		{
			hash = (hash << 4) + data[i];

			if ((x = hash & 0xF0000000L) != 0)
			{
				hash ^= (x >> 24);
				hash &= ~x;
			}
		}

		return (hash & 0x7FFFFFFF);
	}
}