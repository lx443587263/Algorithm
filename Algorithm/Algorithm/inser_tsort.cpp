#include <stdio.h>


void insert_sort(int a[], int n);

int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	insert_sort(a, sizeof(a) / sizeof(a[0]));

	return 0;
}

//void exchange(int i,int j)
//{
//	int temp = i;
//	i = j;
//	j = temp;
//}

void insert_sort(int a[], int n)
{
	int temp=0;
	int j = 0;
	for (int i = 1; i <= n-1; ++i)
	{
		temp = a[i];
		for ( j= i-1; temp<a[j]&&j>=0; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}

}