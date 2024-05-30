#pragma once

template<typename T>
class DynamicArray
{
private:
	T* m_data;
	int m_totalMem;
	int m_usedMem;

public:
	DynamicArray(int size);
	DynamicArray(DynamicArray& copy);
	~DynamicArray();
	void operator = (DynamicArray& copy);

	void AddToEnd(T newElement);	//	adds an element to the end of the array
	void RemoveFromEnd();	//	removes the element at the end of the array

	void AddToIndex(int index, T newElement);	//	adds an element at an index
	void RemoveAtIndex(int index);	//	removes an element from an index

	void Sort();	//	bubble sorts the array
	void Clean();	//	deallocates unused memory
	void Clear();	//	clears the array

	int Search(T search);	//	binary search

	int* Concatenate(DynamicArray& other);	//	concatenates other.m_data to m_data, and returns it
	int* operator + (DynamicArray& other);	//	same as Concatenate()

	int operator [] (int index);

	//void Randomise();

	void Rotate(int rotation);	//	shifts all elements in m_data by rotation
								//	if overflow/underflow, elements wrap around
};