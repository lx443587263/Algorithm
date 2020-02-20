#include <stdio.h>

typedef struct _Value
{
	int current;
	int other;

} value;

int arr[] = { 1,2,100,3 };
value arrs[4][4] = { 0 };

value f(int min, int max);
value ff(int min, int max);
int main()
{
	value v = ff(0, 3);
	printf("%i\n",v.current);
	return 0;
}

//value f(int min,int max)
//{
//	value val;
//	if (min == max)
//	{
//		val.current = min;
//		val.other = 0;
//		return val;
//	}
//
//	value v_l = f(min+1,max);
//	value v_r = f(min, max - 1);
//
//	if (v_l.other + arr[min] - v_l.current > v_r.other + arr[max] - v_r.current)
//	{
//		val.current = v_l.other + arr[min];
//		val.other = v_l.current;
//	}
//	else
//	{
//		val.current = v_r.other + arr[max];
//		val.other = v_r.current;
//	}
//	return val;
//}

value ff(int min, int max)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (i == j)
			{
				arrs[i][j].current = arr[i];
				arrs[i][j].other = 0;
			}
			
		}
	}

	for (int d = 1; d <= 3; ++d)
	{
		for (int i = 0; i <= 3 - d; ++i)
		{
			int j = d + i;
			int left = arrs[i + 1][j].other + arr[i];
			int right = arrs[i][j - 1].other + arr[j];
			if (left - arrs[i + 1][j].current > right - arrs[i][j - 1].current)
			{
				arrs[i][j].current = left;
				arrs[i][j].other = arrs[i + 1][j].current;
			}
			else
			{
				arrs[i][j].current = right;
				arrs[i][j].other = arrs[i][j-1].current;
			}
		}
	}
	return arrs[0][3];
}