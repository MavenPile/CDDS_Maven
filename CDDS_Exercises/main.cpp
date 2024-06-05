#include <iostream>
#include <chrono>
#include "Utils.h"

using namespace std;
using namespace std::chrono;

int main()
{
	const int size = 100;

	int* values = new int[size];

	srand(time(nullptr));

	for (int i = 0; i < size; i++)
	{
		values[i] = rand() % size;
	}
	
	high_resolution_clock::time_point t1, t2;

	t1 = high_resolution_clock::now();

	BubbleSort(values, size);

	t2 = high_resolution_clock::now();

	for (int i = 0; i < size; i++)
	{
		cout << values[i] << endl;
	}

	cout << endl << endl;

	cout << "Bubble sort took " << (t2 - t1).count() << " nanoseconds" << endl;
	
	delete[] values;

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	
	return 0;
}