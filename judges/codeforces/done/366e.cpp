#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 2005
#define SMAX 100005
#define KMAX 15
#define INF 1e9

int n, m, k, s, x, song[SMAX], comp[MAX][MAX], min1[KMAX], max1[KMAX], min2[KMAX], max2[KMAX];

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &s);
	for(int i=1; i<=k; ++i) min1[i] = min2[i] = INF, max1[i] = max2[i] = -INF;	
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
		{
			scanf("%d", &x);
			min1[x] = min(min1[x], i+j); max1[x] = max(max1[x], i+j);
			min2[x] = min(min2[x], i-j); max2[x] = max(max2[x], i-j);
			comp[i][j] = -INF;
		}
	for(int i=0; i<s; ++i) scanf("%d", &song[i]);
	
	for(int i=1; i<=k; ++i)
		for(int j=1; j<=k; ++j)
			comp[i][j] = comp[j][i] = max(comp[i][j], max(max1[i] - min1[j], max2[i] - min2[j]));

	int sol = -1;
	for(int i=1; i<s; ++i) sol = max(sol, comp[song[i-1]][song[i]]);
	printf("%d\n", sol);

	return 0;
}

