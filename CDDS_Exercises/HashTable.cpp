#include "HashTable.h"
#include <cstring>

using namespace std;

template<typename T>
HashTable<T>::HashTable(unsigned int size) {
	m_size = size;
	m_data = new T[m_size];
}

template<typename T>
HashTable<T>::~HashTable() {
	delete[] m_data;
}

template<typename T>
void HashTable<T>::Add(T& object, const string& key) {
	unsigned int hashedKey = HashFunction(key);	//	hash key
	//hashedKey = hashedKey % m_size;	//	clamp hashedKey value to fit in table

	m_data[hashedKey] = object;
}

template<typename T>
void HashTable<T>::Remove(const string& key) {
	unsigned int hashedKey = HashFunction(key);
	//hashedKey = hashedKey % m_size;

	delete m_data[hashedKey];
}

template<typename T>
void HashTable<T>::Clear(const string& key) {
	
}

template<typename T>
T& HashTable<T>::operator[](const string& key) {
	auto hashedKey = HashFunction(key) % m_size;	//	hashes the key input
	return m_data[hashedKey];	//	returns a value in the table at the hashed key
}

template<typename T>
const T& HashTable<T>::operator[](const string& key) const {
	auto hashedKey = HashFunction(key) % m_size;
	return m_data[hashedKey];
}

template<typename T>
unsigned int HashTable<T>::HashFunction(const char* key) {
	unsigned int hash = 0, x = 0;

	for (unsigned int i = 0; i < strlen(key); i++) {
		hash = (hash << 4) + key[i];

		if ((x = hash & 0xF0000000L) != 0) {
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF);
}