#include <stdio.h>

template<typename T>
void insert_sort(T *a, const size_t n)
{
	T temp = 0, j = 0;
	for (T i = 1; i <= n - 1; ++i)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	insert_sort(a, sizeof(a) / sizeof(a[0]));

	return 0;
}

