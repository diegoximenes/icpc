#include<cstdio>
using namespace std;

#define MAX 200000
#define INF (int) 1e9

int main()
{
	int n, k, cum[MAX];
		
	scanf("%d %d", &n, &k);
	cum[0] = 0;
	for(int i=1; i<=n; ++i)
	{
		int v;
		scanf("%d", &v);
		cum[i] = cum[i-1] + v;
	}

	int sol = INF, ind;
	for(int i=1; i<=n; ++i)
	{	
		if(i+k-1 > n) break;
		int nsol = cum[i+k-1] - cum[i-1];
		if(nsol < sol)
		{
			sol = nsol;
			ind = i;
		}
	}
	printf("%d\n", ind);
	
	return 0;
}