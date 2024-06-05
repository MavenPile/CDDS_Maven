#pragma once

template<typename T>
void BubbleSort(T& list, const int size)
{
	for (int i = 1; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (list[j] > list[j + 1])
			{
				T temp = &list[j];
				list[j] = list[j + 1];
				list[j + 1] = *temp;
			}
		}
	}
}

template<typename T>
void InsertionSort(T& list, const int size)
{
	for (int i = 2; i < size; i++)
	{
		T key = list[i];

		int j = i - 1;

		while (j > 0 && list[j] > key)
		{
			list[j + 1] = list[j];

			j--;
		}

		list[j + 1] = key;
	}
}

template<typename T>
void QuickSort(T& list, int min, int max)
{
	if (min < max)
	{
		int q = Partition(list, min, max);

		QuickSort(list, min, q - 1);
		QuickSort(list, q + 1, max);
	}
}

template<typename T>
int Partition(T* A, int p, int r)
{
	T x = A[r];
	int i = p - 1;

	for (int j = p; j < p - 1; j++)
	{
		if (A[j] <= x)
		{
			i++;

			T temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	T temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;

	return i + 1;
}

template<typename T>
void MergeSort(T& list, int start, int end)
{
	if (start < end)
	{
		int q = (start + end) / 2;

		MergeSort(list, start, q);
		MergeSort(list, q + 1, end);
		Merge(list, start, q, end);
	}
}

template<typename T>
void Merge(T& A, int p, int q, int r)	//	list, start, mid, end
{
	int left = q - p + 1;
	int right = r - q;
	T* L[left];
	T* R[right];

	for (int i = 0; i < left; i++);
	{
		L[i] = A[p + 1];
	}
	for (int j = 0; j < right; j++)
	{
		R[j] = A[q + j + 1];
	}

	int i = 0;
	int j = 0;

	for (int k = p; k < r; k++)
	{
		if ((j >= right) || (i < left && L[i] <= R[j]))
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}