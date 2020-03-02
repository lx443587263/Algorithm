#include <stdio.h>
#include <string>

int pmt[100] = { 0 };
int bm_table[100] = { 0 };

int bm(const char* str, const char* sub);
int kmp(const char* str, const char* sub);
int str_str(const char* str, const char* sub);
int main(int ac, char* av[])
{
	char src[] = "GATTATGCCTAGAGTCTAA";
	char pattern[] = "GAGTCTA";
	int where = str_str(src, pattern);
	return 0;
}


int str_str(const char* str, const char* sub)
{
	int i=0, j = 0;
	while (str[i]!='\0')
	{
		j = 0;
		while (str[j]!='\0'&&str[i+j]==sub[j])
		{
			++j;
		}
		if (sub[j] == '\0')
		{
			return i;
		}
		++i;
	}
	return -1;
}

//kmp
void init_kmp(const char* str)
{
	int len = strlen(str);
	for (int i = 1; i <=len; ++i)
	{
		char sub[100] = { '\0' };
		strcpy_s(sub, str);
		sub[i] = '\0';
		for (int j = 1; j <=i-1; j++)//找到前缀&&后缀
		{
			char prefix[100] = { 0 };
			char suffix[100] = { 0 };
			strcpy_s(prefix, sub);
			strcpy_s(suffix, sub + i - j);
			prefix[j] = '\0';
			if (strcmp(prefix, suffix) == 0)
			{
				pmt[i - 1] = j;
			}
		}

	}
}
int kmp(const char* str, const char* sub)
{
	init_kmp(sub);
	int i=0, j = 0;
	while (str[i]!= '\0'&&sub[j]!='\0')
	{
		if (str[i] != sub[j])
		{
			if (j == 0)
			{
				++i;
			}
			else
			{
				j = pmt[j-1];
			}
		}else
		{
			j++;
			i++;
		}
	}
	if (sub[j] == '\0')
	{
		return i-j;
	}
	return -1;

}

//bm
void init_bm(const char* pattern)
{
	int len = strlen(pattern);
	for (int i = len-1; i>0; --i)
	{
		char sub_surfixx[100];
		int k = len - i;
		bm_table[i] = 0;
		for (int j = i-1; j >=0; --j)
		{
			strcpy_s(sub_surfixx, pattern + j);
			sub_surfixx[k] = '\0';
			if (strcmp(sub_surfixx,pattern + i) == 0)
			{
				bm_table[i] = i-j;
				break;
			}
		}
		if (i < len - 1)
		{
			if (bm_table[i] < bm_table[i + 1])
			{
				bm_table[i] = bm_table[i + 1];
			}

		}
		
	}
}
int next_good(int where)
{
	return bm_table[where + 1];
}
int next_bad(const char* const pattern, int where, char bad)
{
	for (int i = where-1; i >=0; --i)
	{
		if (pattern[i] == bad)
		{
			return where - i;
		}
	}
}
int bm(const char* str, const char* sub)
{
	init_bm(sub);
	int str_len = strlen(str);
	int len = strlen(sub);
	int i = len - 1, j = len - 1;
	while (i<str_len)
	{
		j = len - 1;
		while (sub[j]==str[i-(len-1-j)]&&j>=0)//相等
		{
			--j;
		}
		if (j < 0)//完全匹配
		{
			return i - (len - 1);
		}
		else//不相等
		{
			if (j == len - 1)//最后一位,j指针始终在pattern串的头
			{
				++i;
			}
			else
			{
				int good = next_good(j);
				int bad = next_bad(sub,j, str[i-(len - 1 - j)]);
				i+= bad > good ? bad : good;
			}
		}
	}
	return -1;
}
