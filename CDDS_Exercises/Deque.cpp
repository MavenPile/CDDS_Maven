#include "Deque.h"

template<typename T>
inline Deque<T>::Deque()
{
	m_data = new T[0];
	m_size = 0;
	m_front = -1;
	m_back = -1;
}

template<typename T>
Deque<T>::Deque(int capacity)
{
	m_data = new T[capacity];
	m_size = capacity;
	m_front = -1;
	m_back = -1;
}

template<typename T>
Deque<T>::~Deque()
{
	delete[] m_data;
}

template<typename T>
bool Deque<T>::IsEmpty()
{
	if (-1 == m_front || -1 == m_back)
	{
		return true;
	}

	return false;
}

template<typename T>
int Deque<T>::Size()
{
	return 0;
}

template<typename T>
void Deque<T>::PushFront(T value)
{
}

template<typename T>
void Deque<T>::PushBack(T value)
{
}

template<typename T>
void Deque<T>::PopFront()
{
}

template<typename T>
void Deque<T>::PopBack()
{
}

template<typename T>
T Deque<T>::Front()
{
	return T();
}

template<typename T>
T Deque<T>::Back()
{
	return T();
}