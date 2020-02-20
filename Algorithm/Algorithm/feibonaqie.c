#include <stdio.h>
#include <stdlib.h>

int f(int n);

int main()
{
	int a = f(9);
	printf("%i\n",a);
	return 0;
}

//int f(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return f(n - 1) + f(n - 2);
//	
//}

int ff(int n)
{
	int* arr = (int*)malloc(sizeof(int)*(n + 1));
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= n; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int r = arr[n];
	free(arr);
	arr = NULL;
	return 0;

}