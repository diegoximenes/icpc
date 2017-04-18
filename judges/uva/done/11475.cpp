#include<cstdio>
#include<cstring>
using namespace std;

#define MAXT 100000 + 10
#define MAXP 100000 + 10

char t[MAXT], p[MAXP];
int b[MAXT], n, m;

void kmpPreProcess()
{
	int i=0, j= -1;
	b[0] = -1;
	while(i < m)
	{
		while(j >= 0 && p[i] != p[j])
			j = b[j];
		++i; ++j;
		b[i] = j;
	}
}

int kmpSearch()
{
	int i=0, j=0;
	while(i < n)
	{
		while(j >= 0 && t[i] != p[j])
			j = b[j];
		++i; ++j;
	}
	return j;
}

int main()
{
	while(gets(t) != NULL)
	{
		n = m = strlen(t);
		for(int i=0; i<n; ++i)
			p[i] = t[n-i-1];

		kmpPreProcess();
		int j = kmpSearch();
		printf("%s", t);
		for(int i=j; i<m; ++i)
			putchar(p[i]);
		puts("");
	}

	return 0;
}
