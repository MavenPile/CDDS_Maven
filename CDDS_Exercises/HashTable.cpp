#include "HashTable.h"
#include <cstring>

using namespace std;

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
T& HashTable<T>::operator[](const string& key)
{
	auto hashedKey = hash(key) % m_size;
	return m_data[hashedKey];
}

template<typename T>
const T& HashTable<T>::operator[](const string& key) const
{
	auto hashedKey = hash(key) % m_size;
	return m_data[hashedKey];
}

template<typename T>
unsigned int HashTable<T>::HashFunction(const string& key)
{
	return 0;
}