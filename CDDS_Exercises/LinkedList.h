#pragma once

template<typename T>
class LinkedList
{
private:
	//	NODE

	//template<typename T>
	class Node
	{
	public:
		//	VARIABLES

		T m_data;
		Node* m_previous;
		Node* m_next;

		//	CONSTRUCTORS

		Node();
		Node(T value);
	};
	
	//	ITERATOR

	class Iterator
	{
	private:
		//	VARIABLES

		Node* m_currentNode;

	public:
		//	CONSTRUCTORS

		Iterator();
		Iterator(Node& node);

		//	METHODS

		void SetNode(Node& newNode);
		void SetData(T newData);

		Node GetNode();
		T GetData();

		T Current();
		T operator * ();

		void MoveNext();
		void operator ++ (int i);

		void MovePrev();
		void operator -- (int i);
	};

	//	VARIABLES

	Iterator* m_head;
	Iterator* m_tail;
	
	//	PRIVATE METHODS

	bool p_CheckEmpty(Iterator& iterator);
	void p_RemoveNext(Iterator& iterator, T value);
	int p_Counting(Iterator& iterator, int& count);

public:
	
	//	CONSTRUCTOR

	LinkedList();
	~LinkedList();
	
	//	METHODS

	void PushFront(T value);	//	adds a value to the beginning of the list
	void PushBack(T value);	//	adds a value to the end of the list
	void InsertAfter(Iterator* iterator, T value);	//	inserts a value in the specified iterator

	Iterator Begin();	//	returns an iterator for the beginning of the list
	Iterator End();	//	returns an iterator for the end of the list
	T First();	//	returns the first value of the list
	T Last();	//	returns the last value of the list

	int Count();	//	returns the number of values in the list

	void Erase(Iterator* iterator);	//	removes an element in the list by its iterator
	void Remove(T value);	//	removes all elements containing the specified value
	void PopBack();	//	removes the last element of the list
	void PopFront();	//	removes the first element of the list
	bool IsEmpty();	//	returns a bool of if the list is empty of data
	void Clear();	//	clears all elements of the list
};