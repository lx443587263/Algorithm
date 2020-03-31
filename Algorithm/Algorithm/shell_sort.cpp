
template<typename T>
void shell_sort(T *a, const size_t n)
{
	T i = 0, j = 0, k = 0, temp = 0;
	for ( k =n/ 2; k >=1; k/=2)
	{
		for (i = k; i <= n - 1; ++i)
		{
			temp = a[i];
			for ( j = i-k; j>0&&a[j]>temp; j-=k)
			{
				a[j + k] = a[j];
			}
			a[j + k] = temp;
		}
	}
}

int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	shell_sort(a, sizeof(a) / sizeof(a[0]));
	return 0;
}


