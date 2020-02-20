#include <stdio.h>


void exchange(int a[], int i, int j);
void quick_sort(int a[], int n);

int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	quick_sort(a, sizeof(a) / sizeof(a[0]));
	return 0;
}


void quick_sort(int a[],int n)
{
	int min_index = 0;
	for (int i = 0; i < n-1; ++i)
	{
		min_index = i;
		for (int j = i+1; j < n; ++j)
		{
			if (a[j] < a[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			exchange(a, min_index, i);
		}
	}

}



void exchange(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}