#include <iostream>

void quick_sort(int a[], int left, int right);
void exchange(int a[], int i, int j);

int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	quick_sort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
	return 0;

}

void quick_sort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int min = left, max = right - 1, privot = right;
	while (min<max)
	{
		while (a[min]<=a[privot]&&min<max)
		{
			++min;
		}
		while (a[max]>a[privot]&&min<max)
		{
			--max;

		}
		if (min < max)
		{
			exchange(a, min, max);
		}
	}
	if (a[min] > a[privot])
	{
		exchange(a, min, privot);
		privot = min;
	}
	quick_sort(a,left,privot-1);
	quick_sort(a,privot+1,right);
}

void exchange(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}