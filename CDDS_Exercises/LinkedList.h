#pragma once

class Node;

class LinkedList
{
private:
	//	VARIABLES

	Node* m_head;
	Node* m_tail;

	bool CheckEmpty(Node& iterator);
	void RemoveNext(Node& iterator, int value);
	int* Counting(Node* iterator, int* count);

public:
	
	//	CONSTRUCTOR

	LinkedList();
	~LinkedList();
	
	//	METHODS

	void PushFront(int value);	//	adds a value to the beginning of the list
	void PushBack(int value);	//	adds a value to the end of the list
	void InsertAfter(Node* iterator, int value);	//	inserts a value in the specified iterator

	Node* Begin();	//	returns an iterator for the beginning of the list
	Node* End();	//	returns an iterator for the end of the list
	int First();	//	returns the first value of the list
	int Last();	//	returns the last value of the list

	int Count();	//	returns the number of values in the list

	void Erase(Node* iterator);	//	removes an element in the list by its iterator
	void Remove(int value);	//	removes all elements containing the specified value
	void PopBack();	//	removes the last element of the list
	void PopFront();	//	removes the first element of the list
	bool IsEmpty();	//	returns a bool of if the list is empty of data
	void Clear();	//	clears all elements of the list
};