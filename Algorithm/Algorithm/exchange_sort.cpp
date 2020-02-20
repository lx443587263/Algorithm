#include <stdio.h>


void exchange(int a[], int i, int j);
void exchange_sort(int a[], int n);

int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	exchange_sort(a, sizeof(a) / sizeof(a[0]));
	return 0;
}

void exchange(int a[],int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void exchange_sort(int a[], int n)
{
	bool isexchange = false;
	for (int i = n-1; i>=1; --i)
	{
		for (int j = 1; j <=i; ++j)
		{
			if (a[j] < a[j-1])
			{
				exchange(a,j,j-1);
				isexchange = true;
			}
		}
		if (!isexchange)
			return;
	}
}