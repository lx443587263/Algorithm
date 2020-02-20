#include <iostream>
#include <stdlib.h>


void con(int a[], int min, int max, int b[]);
void divide(int a[], int min, int max, int b[]);
void megring_sort(int a[], int n);

int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	megring_sort(a, sizeof(a) / sizeof(a[0]));
	return 0;
}


void megring_sort(int a[], int n)
{
	int *temp=(int*)malloc(n * 4);
	divide(a, 0, n - 1, temp);
	free(temp);

}

void divide(int a[], int min, int max, int b[])
{
	if (min == max)
		return;
	int mid = (min + max) / 2;
	divide(a, min, mid, b);
	divide(a, mid + 1, max, b);
	con(a, min, max, b);
}

void con(int a[], int min, int max, int b[])
{
	int mid = (min + max) / 2;
	int i = min, j = mid + 1, k = min;
	while (k<=max)
	{
		if (i <= mid && j <= max)
		{
			if (a[i] <=a[j])
			{
				b[k] = a[i++];
			}
			else
			{
				b[k] = a[j++];
			}
		}
		else if (j<=max)
		{
			b[k] = a[j++];
		}
		else
		{
			b[k] = a[i++];
		}
		++k;
	}
	for ( k = min; k <=max; k++)
	{
		a[k] = b[k];
	}
}