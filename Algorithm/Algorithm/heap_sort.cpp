#include <iostream>

void exchange(int a[], int i, int j);
void heapif(int a[], int root_index, int last_index);
void create_heap(int a[], int last_index);
void heap_sort(int a[], int n);


int main()
{
	int a[] = { 2,3,1,7,4,5,6,9,8,0 };
	heap_sort(a, sizeof(a) / sizeof(a[0]));
	return 0;

}

void heapif(int a[], int root_index, int last_index)
{
	int left_index = root_index*2 + 1;
	int right_index = left_index + 1;
	int max_index = root_index;
	//终止条件
	if (left_index > last_index)
		return;
	if (a[left_index] > a[max_index])
		max_index = left_index;
	if (a[right_index] > a[max_index] && right_index <= last_index)
		max_index = right_index;
	if (max_index != root_index)
	{
		exchange(a, max_index, root_index);
		heapif(a, max_index, last_index);
	}
}

void create_heap(int a[], int last_index)
{
	int start_pos = (last_index - 1)/2;
	for (int i = start_pos;i>=0;--i)
	{
		heapif(a, i, last_index);
	}
}

void heap_sort(int a[], int n)
{
	int cur_pos = n - 1;
	create_heap(a, cur_pos);
	for (; cur_pos>0; --cur_pos,heapif(a,0,cur_pos))//堆化，交换
	{
		exchange(a, 0, cur_pos);
	}
}


void exchange(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}