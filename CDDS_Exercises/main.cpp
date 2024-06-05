#include <iostream>
#include <chrono>
#include "Utils.h"

using namespace std;
using namespace std::chrono;

int main()
{
	const int size = 100;

	int* values = new int[size];
	int* valuesToSort = new int[size];

	srand(time(nullptr));

	for (int i = 0; i < size; i++)
	{
		values[i] = rand() % size;
		cout << values[i] << ", ";
	}
	
	cout << endl << endl;


	high_resolution_clock::time_point t1, t2;

	memcpy(valuesToSort, values, sizeof(int) * size);

	t1 = high_resolution_clock::now();

	MergeSort(valuesToSort, 0, size - 1);

	t2 = high_resolution_clock::now();

	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << valuesToSort[i] << ", ";
	}

	cout << endl << endl;

	cout << "Sorting took " << (t2 - t1).count() << " nanoseconds..." << endl;

	delete[] values;
	delete[] valuesToSort;

	cout << endl;

	system("pause");

	return 0;
}