#include "Stack.h"

template<typename T>
Stack<T>::Stack()
{
	m_data = new T[0];
	m_size = 0;
	m_top = -1;
}

template<typename T>
Stack<T>::Stack(int capacity)
{
	m_data = new T[capacity];
	m_size = capacity;
	m_top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] m_data;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	if (-1 == m_top)
	{
		return true;
	}

	return false;
}

template<typename T>
int Stack<T>::Size()
{
	return m_top + 1;
}

template<typename T>
void Stack<T>::Push(T value)
{
	m_top++;

	if (-1 == m_top)
	{
		float* temp = new float[m_size * 2];

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
void Stack<T>::Pop()
{
	if (m_top >= 0)
	{
		m_data[m_top] = 0.f;
		m_top--;
	}
}

template<typename T>
T Stack<T>::Top()
{
	if (0 > m_top)
	{
		return nullptr;
	}
	
	return m_data[m_top];
}