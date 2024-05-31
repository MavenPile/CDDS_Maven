#pragma once

template<typename T>
class Queue
{
private:
	//	VARIABLES

	T* m_data;
	int m_size;
	int m_top;

public:
	//	CONSTRUCTORS

	Queue(int capacity);
	~Queue();

	//	METHODS

	bool IsEmpty();

	int Size();

	void Push(T value);

	void Pop();

	T Front();
};