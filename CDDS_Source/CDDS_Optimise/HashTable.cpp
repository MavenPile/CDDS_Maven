#include "HashTable.h"
#include "string"

template<typename T>
unsigned int HashTable<T>::HashFunction(const char* key)
{
	unsigned int hash = 0, x = 0;

	for (unsigned int i = 0; i < strlen(key); i++)
	{
		hash = (hash << 4) + key[i];

		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF) % m_size;
}

template<typename T>
const unsigned int HashTable<T>::HashFunction(const char* key) const
{
	unsigned int hash = 0, x = 0;

	for (unsigned int i = 0; i < strlen(key); i++)
	{
		hash = (hash << 4) + key[i];

		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF) % m_size;
}

template<typename T>
HashTable<T>::HashTable()
{
	m_size = 100;
	m_data = new T[m_size];
}

template<typename T>
HashTable<T>::HashTable(unsigned int size)
{
	m_size = size;
	m_data = new T[m_size];
}

template<typename T>
HashTable<T>::~HashTable()
{
	delete[] m_data;
}

template<typename T>
void HashTable<T>::Add(const T& item, const char* key)
{
	unsigned int hashedKey = HashFunction(key);

	m_data[hashedKey] = item;
}	//	currently doesn't avoid collisions

template<typename T>
void HashTable<T>::Remove(const char* key)
{
	unsigned int hashedKey = HashFunction(key);

	m_data[hashedKey] = NULL;
}

template<typename T>
void HashTable<T>::Clear()
{
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = NULL;
	}
}

template<typename T>
T& HashTable<T>::DataAt(const char* key)
{
	unsigned int hashedKey = HashFunction(key);
	return m_data[hashedKey];
}

template<typename T>
const T& HashTable<T>::DataAt(const char* key) const
{
	unsigned int hashedKey = HashFunction(key);
	return m_data[hashedKey];
}

template<typename T>
T& HashTable<T>::operator[](const char* key)
{
	return DataAt(key);
}

template<typename T>
const T& HashTable<T>::operator[](const char* key) const
{
	return DataAt(key);
}
