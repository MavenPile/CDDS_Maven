#pragma once

template<typename T>
class HashTable
{
private:
	unsigned int HashFunction(const char* key);

	T* m_data;
	unsigned int m_size;

public:
	HashTable();
	HashTable(unsigned int size);
	~HashTable();

	void Add(T& item, const char* key);
	void Remove(const char* key);
	void Clear();

	T& DataAt(const char* key);
	T& operator [] (const char* key);
	const T& operator [] (const char* key) const;
};