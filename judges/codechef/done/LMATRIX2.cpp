#include<cstdio>
#include<vector>
using namespace std;

#define MAX 100
#define pb push_back

int main()
{
	int n, m, a[MAX][MAX], p[MAX][MAX];
	vector<int> x, y, k;

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			scanf("%d", &p[i][j]);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			scanf("%d", &a[i][j]);
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(a[i][j] != 0)
			{
				x.pb(i); y.pb(j);
				for(int l=0; l<=10000; ++l)
					if((a[i][j] + l)%p[i][j] == 0)
					{
						k.pb(l);
						break;
					}
			}

	printf("%d\n", x.size());
	for(int i=0; i<(int)x.size(); ++i)
		printf("%d %d %d %d %d\n", x[i]+1, y[i]+1, x[i]+1, y[i]+1, k[i]);

	return 0;
}
