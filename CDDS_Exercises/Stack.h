#pragma once

template<typename T>
class Stack
{
private:
	//

	T* m_data;
	int m_size;
	int m_top;

public:
	//	CONSTRUCTORS

	Stack();
	Stack(int capacity);
	~Stack();

	//	METHODS

	bool IsEmpty();
	int Size();
	void Push(T value);
	void Pop();
	T Top();
};