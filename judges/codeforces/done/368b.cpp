#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 100010

int main()
{
	int n, m, diff[MAX], v[MAX];
	bool mark[MAX];

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	
	memset(mark, 0, sizeof(mark));
	diff[n-1] = 1; mark[v[n-1]] = 1;
	for(int i=n-2; i>=0; --i)
	{
		diff[i] = diff[i+1];
		if(!mark[v[i]]) ++diff[i], mark[v[i]] = 1;
	}
	while(m--)
	{
		int l;
		scanf("%d", &l);
		printf("%d\n", diff[l-1]);
	}

	return 0;
}
