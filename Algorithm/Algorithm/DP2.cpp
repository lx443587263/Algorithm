#include <stdio.h>
#include <stdlib.h>


int a[] = { 1,4,8,3,7,6,5,2 };
bool f(int n, int c);
bool ff(int n, int c);
int main(int ac,char* av[])
{
	bool r = ff(7, 12);
	return 0;
}

bool f(int n, int c)
{
	if (c == 0)
	{
		return true;
	}
	if (n == 0)
	{
		return c==a[0];
	}

	bool left = f(n - 1, c);
	bool right = false;
	if (c  >= a[n])
		right = f(n - 1, c - a[n]);

	return left||right;

}

bool ff(int n, int c)
{
	//bool arr[7][12] = { 0 };
	
	bool **arr =(bool **)malloc(n * sizeof(bool*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (bool *)malloc(c);
	}

	for (int i = 0; i < c; ++i)
	{
		if (i == a[0])
		{
			arr[0][i] = true;
		}
		else
		{
			arr[0][i] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		arr[i][0] = true;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j=1; j < c; ++j)
		{
			bool left = arr[i-1][j];
			bool right = false;
			if (j > a[i])
				right = arr[i - 1][j - a[i]];

			arr[i][j] = left || right;
		}
	}
	return arr[n][c];

}