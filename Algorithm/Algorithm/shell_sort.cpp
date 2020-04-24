#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>

class A
{
public:
	int _id;
};

class gen_class
{
public:
	A operator ()(void)
	{
		return { rand() % 100 };
	}
};

A gen(void)
{
	return { rand() % 100 };
}

class A_compare
{
public:
	bool operator ()(A const& a,A const& b)
	{
		return a._id < b._id;
	}
}comp;

template <typename T,typename compare>
void shell_sort(std::vector<T>& vec, compare comp)
{
	
	for (int k = vec.size()/2;k>=1;k/=2)
	{
		for (int i=k;i<=vec.size()-1;++i)
		{
			auto temp = std::move(vec[i]);
			int j = i - k;
			for (;comp(temp,vec[j]);)
			{

				vec[j + k] = std::move(vec[j]);
				j -= k;
				if (j < 0)
					break;
			}
			vec[j + k] = std::move(temp);
		}
	}
}

int main()
{
	std::vector<A> vec(10);
	srand(static_cast<unsigned>(time(nullptr)));

	std::generate(vec.begin(),vec.end(),gen);

	shell_sort(vec, comp);
	for (auto& it : vec)
	{
		std::cout << it._id << std::endl;
	}
	return 0;
}
