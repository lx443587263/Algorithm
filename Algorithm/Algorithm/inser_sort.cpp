#include <stdio.h>
#include <iostream>
#include<ctime>
#include <algorithm>
#include <vector>


/*template<typename T>
void insert_sort(T *a, const size_t n)
{
	T temp = 0, j = 0;
	for (T i = 1; i <= n - 1; ++i)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}*/

class A
{
public:
	int _id;
};

class Gen_fn
{
public:
	A operator ()(void)
	{
		return { rand() % 100 };
	}
}gen;


class A_Comp
{
public:
	bool operator()(A const& a, A const& b)
	{
		return a._id < b._id;
	}
} comp;

template <typename T,typename Compare>
void insert_sort(std::vector<T>& vec, Compare comp)
{
	T temp;
	for (int i = 1; i < vec.size(); ++i)
	{
		temp = std::move(vec[i]);
		int j = i - 1;
		for (; comp(temp, vec[j]);)
		{
			vec[j + 1] = std::move(vec[j]);
			if (--j < 0)
			{
				break;
			}
		}
		vec[j+1] = std::move(temp);
	}
}

//iterator
template <typename T, typename Compare>
void insert_sort1(std::vector<T>& vec, Compare comp)
{
	T temp;
	for (auto it =vec.begin()+1;it!=vec.end();++it)
	{
		temp = std::move(*it);
		auto it_2 = (it - 1);
		for (; comp(temp, *it_2); --it_2)
		{
			*(it_2+1) = std::move(*it_2);
			if (it_2 == vec.begin())
				break;
		}
		if (it_2 == vec.begin())
			*it_2 = std::move(temp);
		else
			*(it_2 + 1) = std::move(temp);
	}
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
	insert_sort(vec, comp);
	for (auto& it : vec)
	{
		std::cout << it._id << std::endl;
	}
	return 0;
}
