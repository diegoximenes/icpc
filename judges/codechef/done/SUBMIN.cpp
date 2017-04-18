#include<cstdio>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 50
#define MAX2 1000010

int v[MAX], cnt[MAX2];

int main()
{
	int n, q;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
		{
			int minx = INF;
			for(int k=i; k<=j; ++k) minx = min(minx, v[k]);
			cnt[minx]++;
		}

	scanf("%d", &q);
	while(q--)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", cnt[x]);
	}

	return 0;
}
