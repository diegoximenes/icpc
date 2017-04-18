#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 250000 + 100

char t[2*MAX], p[MAX];
int b[MAX], n, m;
bool solution = 0;

void kmpPreprocess()
{
	int i=0, j=-1;
	b[0] = -1;
	while(i < m)
	{
		while(j >= 0 && p[i] != p[j])
			j = b[j];
		++i; ++j;
		b[i] = j;
	}
}

void kmpSearch()
{
	int i=0, j=0;
	while(i<n)
	{
		while(j >= 0 && t[i] != p[j])
			j = b[j];
		++i; ++j;
		if(j == m)
		{
			printf("%d\n", i-j);
			solution = 1;
			return;
		}
	}
}

int main()
{
	gets(t);
	sscanf(t, "%d", &m);
	gets(p);
	gets(t);
	n = 2*m;
	
	strncpy(t+strlen(t), t, strlen(t));
	kmpPreprocess();
	kmpSearch();
	
	if(!solution)
		puts("-1");
	
	return 0;
}
