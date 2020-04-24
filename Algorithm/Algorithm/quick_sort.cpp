#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <algorithm>


class A
{
public:
	int _id;
};

class A_compare
{
public:
	bool operator()(A const& a, A const& b)
	{
		return a._id <= b._id;
	}
}comp;

template <typename T,typename Compare>
void quick_sort(std::vector<T>& vec, int left, int right,Compare comp)
{
	int min = left, max = right - 1, prviot = right;
	T temp;
	if (left >= right)
		return;
	while (min<max)
	{
		while (comp(vec[min],vec[prviot]) && min < max)
		{
			/*if (min > max)
				break;*/
			++min;
		}
		while (comp(vec[prviot],vec[max])&&min<max)
		{
			//if (min > max)
			//	break;
			--max;
		}
		if (min<max)
		{
			temp = std::move(vec[min]);
			vec[min] = std::move(vec[max]);
			vec[max] = std::move(temp);
		}
	}
	if (comp(vec[prviot],vec[min]))
	{
		temp = std::move(vec[min]);
		vec[min] = std::move(vec[prviot]);
		vec[prviot] = std::move(temp);
		prviot = std::move(min);
	}
	quick_sort(vec, left, prviot - 1,comp);
	quick_sort(vec, prviot + 1, right,comp);
	
}


A gen_fn(void)
{
	return { rand() % 100 };
}

int main()
{
	std::vector<A> vec(10);

	srand(static_cast<unsigned>(time(nullptr)));

	std::generate(vec.begin(), vec.end(), gen_fn);

	quick_sort(vec,0,9,comp);
	for (auto& it : vec)
	{
		std::cout << it._id << std::endl;
	}
	return 0;
}
