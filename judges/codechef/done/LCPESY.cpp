#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 10010

int main()
{
	int t, cnta[200], cntb[200];
	char a[MAX], b[MAX];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf(" %s %s", a, b);
		memset(cnta, 0, sizeof(cnta));
		memset(cntb, 0, sizeof(cntb));
		
		int lena = strlen(a), lenb = strlen(b);
		for(int i=0; i<lena; ++i) cnta[(int)a[i]]++;
		for(int i=0; i<lenb; ++i) cntb[(int)b[i]]++;

		int sol = 0;
		for(int i=0; i<200; ++i) sol += min(cnta[i], cntb[i]);
		printf("%d\n", sol);
	}

	return 0;
}
