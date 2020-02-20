#include <stdio.h>

void hannota(int n, char from, char via, char to);

int main()
{
	hannota(3,'A','B','C');
	return 0;
}


void hannota(int n,char from,char via,char to)
{
	if (n == 1)
	{
		printf("%c->%c\n", from, to);
		return;
	}

	hannota(n - 1, from, to, via);
	printf("%c->%c\n", from, to);
	hannota(n - 1, via, from, to);
}
