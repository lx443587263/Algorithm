#include <stdio.h>
#include <stdlib.h>

int f(int n, int c);
int val[] = {5,13,9,7,18};
int cap[] = {12,20,16,11,19};

int main()
{
	int res=f(4, 50);
	printf("%i", res);
	
	return 0;
}

//int f(int n, int c)
//{
//	if (n == 0)
//		if (cap[0] > c)
//			return 0;
//
//		else
//			return val[0];
//
//	int no = f(n - 1, c);
//	int yes = no;
//
//	if (cap[n] <= c)
//		yes = f(n - 1, c - cap[n]) + val[n];
//	return yes > no ? yes : no;
//}


int f(int n, int c)
{
	//≥ı ºªØ
	int(*arr)[51] = (int(*)[51])malloc(sizeof(int)*(c+1)*(n+1));
	//int **arr = (int**)malloc(sizeof(int)*(c + 1)*(n + 1));

	for (int i = 0; i < c; ++i)
	{
		if (i < cap[0])
			arr[0][i] = 0;
		else
			arr[0][i] = 5;
	}

	//µ¸¥˙
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 0; j <= c; ++j)
		{
			int no = arr[i-1][j];
			int yes = no;
			if (cap[i] < j)
				yes = arr[i - 1][j - cap[i]] + val[i];
			arr[i][j] = yes > no ? yes : no;
		}
	}
	int r = arr[n][c];
	free(arr);
	arr = NULL;
	return r;
		
}