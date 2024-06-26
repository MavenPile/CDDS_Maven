#pragma once

class string;

template<typename T>
class HashTable
{
private:
	unsigned int HashFunction(const char* key);
	const unsigned int HashFunction(const char* key) const;

	class Bucket;

	Bucket* m_data;
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

private:

	class Bucket
	{
	private:
		T* m_item;
		char* m_key;
	
	public:
		Bucket() {}
		~Bucket() {}

		void Add(const T& item, const char* key)
		{
			m_item = item;
			m_key = key;
		}

		void Clear()
		{
			m_item = nullptr;
			m_key = nullptr;
		}

		T& Data()
		{
			return *m_item;
		}
		const T& Data() const
		{
			return *m_item;
		}

		char* Key()
		{
			return m_key;
		}
		const char* Key() const
		{
			return m_key;
		}
	};

};


//	HOW TO USE
//	
//	
//