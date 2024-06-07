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
	void Add(T& item, const string& key);
	void Remove(const string& key);

	void Clear(const string& key);

	//	OPERATORS
	T& operator [] (const string& key);
	const T& operator [] (const string& key) const;

	struct Bucket
	{
		//	VARIABLES
		T* m_contents;
		int m_size;
		int m_index;

		//	CONSTRUCTORS
		Bucket() { m_contents = new T[2], m_size = 2, m_index = -1; }
		~Bucket() { delete[] m_contents; }

		//	METHODS
		void Add(T& item, unsigned int& key) {
			if (m_index = m_size) {	//	if at max bucket size
				T* temp = new T[m_size + 1];	//	increase bucket size by 1

				for (int i = 0; i < m_size; i++) {
					temp[i] = m_contents[i];
				}

				delete[] m_contents;
				m_contents = temp;
			}
			
			m_index++;
			m_contents[key % m_size] = item;	//	add new item to bucket
		}

		void Remove() {

		}

		T& Query() {

		}
	};

private:

	unsigned int HashFunction(const char* key);

	T* m_data;
	unsigned int m_size;
};


//	HOW TO USE
//	
//	
//