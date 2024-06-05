#pragma once

template<typename T>
class DLinkList
{
private:

	class Node
	{
	public:

		T m_data = 0.f;
		Node* m_prev = nullptr;
		Node* m_next = nullptr;

		Node() {}
		Node(T d) { m_data = d; }
	};

	class Iterator
	{
	private:

		Node* m_current = nullptr;

	public:

		Iterator() {}
		Iterator(Node* n) { m_current = n; }
		Iterator(Iterator* i) { m_current = i->GetNode(); }

		void SetNode(Node* n) { m_current = n; }
		void SetData(T d) { m_current->m_data = d; }

		Node* GetNode() { return m_current; }
		T GetData() { return m_current->m_data; }
		T operator * () { GetData(); }

		void MoveNext() { if (nullptr != m_current->m_next) { m_current = m_current->m_next; } }
		void operator ++ (int i) { MoveNext(); }

		void MovePrev() { if (nullptr != m_current->m_prev) { m_current = m_current->m_prev; } }
		void operator -- (int i) { MovePrev(); }
	};

	//	VARIABLES

	Iterator* m_head = nullptr;
	Iterator* m_tail = nullptr;

	//	PRIVATE METHODS

	int p_Counting(Iterator* iterator, int& count);
	void p_RemoveNext(Iterator* iterator, T value);
	bool p_CheckEmpty(Iterator* iterator);

public:

	//	CONSTRUCTOR

	DLinkList() {}
	~DLinkList() {}

	//	METHODS

	void PushFront(T value);	//	adds a value to the beginning of the list
	void PushBack(T value);	//	adds a value to the end of the list
	void InsertAfter(Iterator* iterator, T value);	//	inserts a value in the specified iterator

	Iterator* Begin() { return m_head; }	//	returns an iterator for the beginning of the list
	Iterator* End() { return m_tail; }	//	returns an iterator for the end of the list
	T First();	//	returns the first value of the list
	T Last();	//	returns the last value of the list

	int Count();	//	returns the number of values in the list

	void Erase(Iterator* iter);	//	removes an element in the list by its iterator
	void Remove(T value);	//	removes all elements containing the specified value
	void PopBack();	//	removes the last element of the list
	void PopFront();	//	removes the first element of the list
	bool IsEmpty();	//	returns a bool of if the list is empty of data
	void Clear();	//	clears all elements of the list
};

