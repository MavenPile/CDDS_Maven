#include "DynamicArray.h"

DynamicArray::DynamicArray(int size)
{
	m_data = new int[size];
	m_totalMem = size;
	m_usedMem = 0;
}

DynamicArray::DynamicArray(DynamicArray& copy)
{
	m_data = new int[*copy.m_data];
	m_totalMem = copy.m_totalMem;
	m_usedMem = copy.m_usedMem;
}

DynamicArray::~DynamicArray()
{
	delete[] m_data;
}

void DynamicArray::operator = (DynamicArray& copy)
{
	m_data = new int[*copy.m_data];
	m_totalMem = copy.m_totalMem;
	m_usedMem = copy.m_usedMem;
}

void DynamicArray::AddToEnd(int newElement)
{
	if (m_usedMem == m_totalMem)
	{
		int* newData = new int[m_totalMem * 2];

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

void DynamicArray::RemoveFromEnd()
{
	m_usedMem -= 1;	//	the memory remains allocated
					//	but this is fine, because it can still be overwritten,
					//	or cleaned up by another function
}

void DynamicArray::AddToIndex(int index, int newElement)
{
	if (m_totalMem == m_usedMem)	//	if array is full
	{
		int* newData = new int[m_totalMem * 2];
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

void DynamicArray::RemoveAtIndex(int index)
{
	for (int i = index; i < m_usedMem; i++)
	{
		m_data[i] = m_data[i + 1];	//	shifts all elements after the index
	}
	m_usedMem -= 1;
}

void DynamicArray::Sort()
{
	for (int i = m_usedMem; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (m_data[j] > m_data[j + 1])
			{
				int temp = m_data[j];
				m_data[j] = m_data[j + 1];
				m_data[j + 1] = temp;
			}
		}
	}
}

void DynamicArray::Clean()
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

void DynamicArray::Clear()
{
	delete[] m_data;
	m_totalMem = 0;
	m_usedMem = 0;
}

int DynamicArray::Search(int search)
{
	Sort();

	int pivot;
	int startIndex = 0;
	int endIndex = m_usedMem;
	int pivotPoint;

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

int* DynamicArray::Concatenate(DynamicArray& other)
{
	int* newData = new int[m_usedMem + other.m_usedMem];
	
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

int* DynamicArray::operator+(DynamicArray& other)
{
	int* newData = new int[m_usedMem + other.m_usedMem];

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

//void DynamicArray::Randomise()
//{
//
//}

void DynamicArray::Rotate(int rotation)
{
	int* newData = new int[m_usedMem];

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
