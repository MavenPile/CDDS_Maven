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
	m_data = new Bucket[m_size];
}

template<typename T>
HashTable<T>::HashTable(unsigned int size)
{
	m_size = size;
	m_data = new Bucket[m_size];
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

	while (m_data[hashedKey].Data() != NULL)
	{
		hashedKey++;
	}

	//m_data[hashedKey].Add(item, key);
}	//	currently doesn't avoid collisions

template<typename T>
void HashTable<T>::Remove(const char* key)
{
	unsigned int hashedKey = HashFunction(key);

	while (m_data[hashedKey].Key() != key)
	{
		hashedKey++;
	}

	m_data[hashedKey].Clear();
}

template<typename T>
void HashTable<T>::Clear()
{
	for (int i = 0; i < m_size; i++)
	{
		m_data[i].Clear();
	}
}

template<typename T>
T& HashTable<T>::DataAt(const char* key)
{
	unsigned int hashedKey = HashFunction(key);
	return m_data[hashedKey].Data();
}

template<typename T>
const T& HashTable<T>::DataAt(const char* key) const
{
	unsigned int hashedKey = HashFunction(key);
	return m_data[hashedKey].Data();
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

//	BUCKET METHODS

template<typename T>
HashTable<T>::Bucket::Bucket()
{
	m_item = nullptr;
	m_key = nullptr;
}

template<typename T>
HashTable<T>::Bucket::~Bucket()
{

}

template<typename T>
void HashTable<T>::Bucket::Add(T& item, char* key)
{
	m_item = item;
	m_key = key;
}

template<typename T>
void HashTable<T>::Bucket::Clear()
{
	m_item = nullptr;
	m_key = nullptr;
}

template<typename T>
T& HashTable<T>::Bucket::Data()
{
	return *m_item;
}

template<typename T>
const T& HashTable<T>::Bucket::Data() const
{
	return *m_item;
}

template<typename T>
char* HashTable<T>::Bucket::Key()
{
	return nullptr;
}

template<typename T>
const char* HashTable<T>::Bucket::Key() const
{
	return nullptr;
}
