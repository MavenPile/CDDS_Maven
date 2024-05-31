#pragma once

template<typename T>
class Deque
{
private:
	//	VARIABLES

	T* m_data;
	int m_size;
	int m_front;
	int m_back;

public:
	//	CONSTRUCTORS

	Deque();
	Deque(int capacity);
	~Deque();

	//	METHODS

	bool IsEmpty();
	int Size();

	void PushFront(T value);
	void PushBack(T value);

	void PopFront();
	void PopBack();

	T Front();
	T Back();
};