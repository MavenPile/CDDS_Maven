#pragma once

class string;

template<typename T>
class HashTable
{
public:

	HashTable(unsigned int size);
	~HashTable();

	T& operator [] (const string& key);

	const T& operator [] (const string& key) const;

private:

	unsigned int HashFunction(const string& key);

	T* m_data;
	unsigned int m_size;
};