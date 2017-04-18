#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 1002
#define mp make_pair

int main()
{
	int t, n, x, y,	dist[MAX*MAX];
	pair<int, int> p[MAX]; 

	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf("%d %d", &x, &y);
			p[i] = mp(x, y);
		}
		
		if(n==0 || n==1)
		{
			printf("Case %d: %d\n", tc, 1);
			break;
		}

		int count = 0;
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
			{
				int a = p[i].first-p[j].first, b = p[i].second-p[j].second;
				dist[count++] = a*a + b*b; 
			}
		sort(dist, dist+count);

		int cons = 2;
		for(int i=1; i<count; ++i)
			if(dist[i-1] != dist[i])
				++cons;
		printf("Case %d: %d\n", tc, cons);
	}

	return 0;
}
