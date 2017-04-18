#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 10010
#define INF (int) 1e9

int fill(int n, int m, int l, int *countWood)
{
	int line, count, n100 = n*100;

	if(n100%l != 0) return INF;
	
	line = l*min(countWood[m], n100/l);
	count = min(countWood[m], n100/l);
	int up = m/2;
	if(m%2 != 0) ++up;
	for(int i=1; i<up && line < n100; ++i)
	{
		count += 2*min(min(countWood[i], countWood[m-i]), (n100 - line)/l);
		line += l*min(min(countWood[i], countWood[m-i]), (n100 - line)/l);

	}
	if(m%2 == 0)
	{
		count += 2*min(countWood[m/2]/2, (n100 - line)/l);
		line += l*min(countWood[m/2]/2, (n100 - line)/l);
	}

	if(line != n100) return INF;
	else return count;
}

int main()
{
	int n, m, k, countWood[MAX], l;

	while(scanf("%d %d %d %d", &n, &m, &l, &k) && n)
	{
		memset(countWood, 0, sizeof(countWood));
		for(int i=0; i<k; ++i)
		{
			int v;
			scanf("%d", &v);
			++countWood[v];
		}

		int sol = min(fill(n, m, l, countWood), fill(m, n, l, countWood));
		if(sol == INF) puts("impossivel");
		else printf("%d\n", sol);
	}

	return 0;
}
