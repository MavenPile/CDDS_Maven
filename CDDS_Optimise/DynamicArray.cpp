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

void DynamicArray::Search()
{
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

void DynamicArray::Randomise()
{
}

void DynamicArray::Rotate()
{
}
