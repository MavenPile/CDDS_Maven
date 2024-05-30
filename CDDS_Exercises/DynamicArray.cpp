#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray(int size)
{
	m_data = new T[size];
	m_totalMem = size;
	m_usedMem = 0;
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray& copy)
{
	m_data = new T[*copy.m_data];
	m_totalMem = copy.m_totalMem;
	m_usedMem = copy.m_usedMem;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] m_data;
}

template<typename T>
void DynamicArray<T>::operator = (DynamicArray& copy)
{
	m_data = new T[*copy.m_data];
	m_totalMem = copy.m_totalMem;
	m_usedMem = copy.m_usedMem;
}

template<typename T>
void DynamicArray<T>::AddToEnd(T newElement)
{
	if (m_usedMem == m_totalMem)
	{
		T* newData = new T[m_totalMem * 2];

		for (int i = 0; i < m_totalMem; i++)
		{
			newData[i] = m_data[i];
			m_usedMem = i;
		}

		delete[] m_data;
		m_data = newData;
	}

	m_data[m_usedMem] = newElement;
	m_usedMem += 1;
}

template<typename T>
void DynamicArray<T>::RemoveFromEnd()
{
	m_usedMem -= 1;	//	the memory remains allocated
					//	but this is fine, because it can still be overwritten,
					//	or cleaned up by another function
}

template<typename T>
void DynamicArray<T>::AddToIndex(int index, T newElement)
{
	if (m_totalMem == m_usedMem)	//	if array is full
	{
		int* newData = new T[m_totalMem * 2];
		for (int i = 0; i < m_totalMem; i++)
		{
			newData[i] = m_data[i];
			m_usedMem = i;
		}
		delete[] m_data;
		m_data = newData;
	}
	
	for (int i = m_usedMem; i >= index; i--)
	{
		m_data[i + 1] = m_data[i];	//	increasing index of existing elements

		if (i == index)
		{
			m_data[i] = newElement;	//	adding new element at index
			break;
		}
	}
	m_usedMem += 1;
}

template<typename T>
void DynamicArray<T>::RemoveAtIndex(int index)
{
	for (int i = index; i < m_usedMem; i++)
	{
		m_data[i] = m_data[i + 1];	//	shifts all elements after the index
	}
	m_usedMem -= 1;
}

template<typename T>
void DynamicArray<T>::Sort()
{
	for (int i = m_usedMem; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (m_data[j] > m_data[j + 1])
			{
				T temp = m_data[j];
				m_data[j] = m_data[j + 1];
				m_data[j + 1] = temp;
			}
		}
	}
}

template<typename T>
void DynamicArray<T>::Clean()
{
	if (m_usedMem < m_totalMem)
	{
		int* newData = new int[m_usedMem];

		for (int i = 0; i < m_usedMem; i++)
		{
			newData[i] = m_data[i];
			m_usedMem = i;
		}

		delete[] m_data;
		m_data = newData;
	}
}

template<typename T>
void DynamicArray<T>::Clear()
{
	m_usedMem = 0;
}

template<typename T>
int DynamicArray<T>::Search(T search)
{
	Sort();

	int pivot;
	int startIndex = 0;
	int endIndex = m_usedMem;
	T pivotPoint;

	while (startIndex <= endIndex)
	{
		pivot = (startIndex + endIndex) / 2;

		pivotPoint = m_data[pivot];

		if (pivotPoint == search)
		{
			return pivot;
		}
		else if (pivotPoint > m_data[pivot])
		{
			endIndex = pivot - 1;
		}
		else
		{
			startIndex = pivot + 1;
		}
	}

	return -1;
}

template<typename T>
int* DynamicArray<T>::Concatenate(DynamicArray& other)
{
	T* newData = new T[m_usedMem + other.m_usedMem];
	
	for (int i = 0; i < m_usedMem; i++)
	{
		newData[i] = m_data[i];
		m_usedMem = i;
	}
	for (int i = 0; i < other.m_usedMem; i++)
	{
		newData[i + m_usedMem] = other.m_data[i];
		m_usedMem += 1;
	}
	
	delete[] m_data;
	m_data = newData;

	return m_data;
}

template<typename T>
int* DynamicArray<T>::operator+(DynamicArray& other)
{
	T* newData = new T[m_usedMem + other.m_usedMem];

	for (int i = 0; i < m_usedMem; i++)
	{
		newData[i] = m_data[i];
		m_usedMem = i;
	}
	for (int i = 0; i < other.m_usedMem; i++)
	{
		newData[i + m_usedMem] = other.m_data[i];
		m_usedMem += 1;
	}

	delete[] m_data;
	m_data = newData;

	return m_data;
}

template<typename T>
int DynamicArray<T>::operator[](int index)
{
	return m_data[index];
}

//void DynamicArray::Randomise()
//{
//
//}

template<typename T>
void DynamicArray<T>::Rotate(int rotation)
{
	T* newData = new T[m_usedMem];

	for (int i = 0; i < m_usedMem; i++)
	{
		if (i + rotation > m_usedMem)
		{
			newData[i] = m_data[m_usedMem - (i + rotation)];
		}
		else
		{
			newData[i] = m_data[i + rotation];
		}
	}
}
