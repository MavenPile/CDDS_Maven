#pragma once

class DynamicArray
{
private:
	int* m_data;
	int m_totalMem;
	int m_usedMem;

public:
	DynamicArray(int size);
	DynamicArray(DynamicArray& copy);
	~DynamicArray();
	void operator = (DynamicArray& copy);

	void AddToEnd(int newElement);	//	adds an element to the end of the array
	void RemoveFromEnd();	//	removes the element at the end of the array

	void AddToIndex(int index, int newElement);	//	adds an element at an index
	void RemoveAtIndex(int index);	//	removes an element from an index

	void Sort();
	void Clean();	//	deallocates unused memory
	void Clear();	//	clears the array

	void Search();

	int* Concatenate(DynamicArray& other);
	int* operator + (DynamicArray& other);

	void Randomise();

	void Rotate();
};

