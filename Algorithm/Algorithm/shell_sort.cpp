#include <stdio.h>

void shell_sort(int a[], int n);
int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	shell_sort(a, sizeof(a) / sizeof(a[0]));
	return 0;
}


void shell_sort(int a[],int n)
{
	int i, j, k, temp;
	for (k =n / 2; k >=1; k/=2)
	{
		for (i = k; i <=n-1; ++i)
		{
			temp = a[i];
			for (j = i-k; temp<a[j]&&j>=0; j-=k)
			{
				a[j + k] = a[j];
			}
			a[j+k] = temp;
		} 
	}
}