#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

class A
{
public:
	int _id;
};

class A_Comp
{
public:
	bool operator()(A const& a, A const& b)
	{
		return a._id < b._id;
	}
} comp;

A gen_fn(void)
{
	return { rand() % 100 };
}

template <typename T,typename compare>
void select_sort(std::vector<T>& vec,compare comp)
{
	int min_index = 0;
	T temp;
	for (int i = 0; i < vec.size()-1; ++i)
	{
		min_index = i;
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (comp(vec[j],vec[min_index]))
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			temp = std::move(vec[i]);
			vec[i] = std::move(vec[min_index]);
			vec[min_index] = std::move(temp);
		}
	}
}

//iterator
template <typename T, typename compare>
void select_sort1(std::vector<T>& vec, compare comp)
{
	T temp;
	for (auto it = vec.begin(); it!=vec.end()-1; ++it)
	{
		auto min_index = it;
		for (auto it_2 = it+1; it_2!=vec.end(); ++it_2)
		{
			if (comp(*it_2,*min_index))
			{
				min_index = it_2;
			}
		}
		if (min_index != it)
		{
			temp = std::move(*it);
			*it = std::move(*min_index);
			*min_index = std::move(temp);
		}
	}
}



int main()
{
	std::vector<A> vec(10);

	srand(static_cast<unsigned>(time(nullptr)));

	std::generate(vec.begin(), vec.end(), gen_fn);
	select_sort1(vec, comp);
	for (auto& it : vec)
	{
		std::cout << it._id << std::endl;
	}
	return 0;
}
