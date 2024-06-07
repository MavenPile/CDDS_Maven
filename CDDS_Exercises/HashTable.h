#pragma once

class string;

template<typename T>
class HashTable
{
public:

	//	CONSTRUCTORS
	HashTable(unsigned int size);
	~HashTable();

	//	METHODS
	void Add(T& object, const string& key);
	void Remove(const string& key);

	void Clear(const string& key);

	//	OPERATORS
	T& operator [] (const string& key);
	const T& operator [] (const string& key) const;

private:

	unsigned int HashFunction(const char* key);

	T* m_data;
	unsigned int m_size;

	struct Pair
	{
		T m_first;
		T m_second;
	};
};


//	HOW TO USE
//	
//	
//