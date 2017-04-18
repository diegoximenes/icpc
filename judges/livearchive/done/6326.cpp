#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 105

int n, m;

inline bool can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<m)
		return 1;
	return 0;
}

int main()
{
	int t, g[MAX][MAX];
	bool mark[MAX];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				scanf("%d", &g[i][j]);

		memset(mark, 0, sizeof(mark));
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				if(g[i][j] != -1)
					for(int k=-1; k<=1; ++k)
						for(int l=-1; l<=1; ++l)
							if(!(l == 0 && k == 0) && can(i+k,  j+l))
								if(g[i][j] == g[i+k][j+l])
									mark[g[i][j]] = 1;
		int count = 0;
		for(int i=0; i<=100; ++i)
			if(mark[i])
				++count;
		printf("%d\n", count);
	}

}
