#include "Queue.h"

template<typename T>
Queue<T>::Queue(int capacity)
{
	m_data = new T(capacity);
	m_size = capacity;
	m_top = -1;
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] m_data;
}

template<typename T>
bool Queue<T>::IsEmpty()
{
	if (-1 == m_top)
	{
		return true;
	}

	return false;
}

template<typename T>
int Queue<T>::Size()
{
	return m_size;
}

template<typename T>
void Queue<T>::Push(T value)
{
	m_top++;

	if (-1 == m_top)
	{
		T* temp = new T[m_size * 2 + 1];

		for (int i = 0; i < m_size; i++)
		{
			temp[i] = m_data[i];
		}

		delete[] m_data;
		m_data = temp;
	}

	m_data[m_top] = value;
}

template<typename T>
void Queue<T>::Pop()
{
	T* temp = new T[m_size - 1];

	for (int i = 0; i < m_size - 1; i++)
	{
		temp[i] = m_data[i + 1];
	}

	delete[] m_data;
	m_data = temp;
}

template<typename T>
T Queue<T>::Front()
{
	return m_data[0];
}