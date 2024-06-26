#pragma once

class string;

template<typename T>
class HashTable
{
private:
	unsigned int HashFunction(const char* key);
	const unsigned int HashFunction(const char* key) const;

	T* m_data;
	unsigned int m_size;

public:
	HashTable();	//	unresolved external symbol error
	HashTable(unsigned int size);
	~HashTable();	//	unresolved external symbol error

	void Add(const T& item, const char* key);	//	unresolved external symbol error
	void Remove(const char* key);
	void Clear();

	T& DataAt(const char* key);
	const T& DataAt(const char* key) const;
	T& operator [] (const char* key);	//	unresolved external symbol error
	const T& operator [] (const char* key) const;
};


//	HOW TO USE
//	
//	
//