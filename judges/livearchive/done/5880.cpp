#include<cstdio>
#include<cstring>
using namespace std;

#define MAXK 1010
#define MAXT 100010

int main()
{
	int lenk, lent, j;
	char k[MAXK], t[MAXT];
	
	while(scanf(" %s %s", k, t) && strcmp(k, "0") != 0)
	{
		lenk = strlen(k); lent = strlen(t);
		j = 0;
		for(int i=0; i<lent; ++i, j++) j %= lenk, putchar((t[i] - 'A' + k[j] - 'A' + 1)%26 + 'A');
		puts("");
	}
}
