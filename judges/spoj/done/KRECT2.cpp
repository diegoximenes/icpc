#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 101
#define MAXL 26

int n, m, krec, dp[MAX][MAX], g[MAX][MAX];
char line[MAX];

inline int set(int i)
{
	return (1 << i);
}

int main()
{	
	gets(line);
	sscanf(line, "%d %d %d", &n, &m, &krec);
	for(int i=0; i<n; ++i, gets(line))
		for(int j=0; j<m; ++j)
		{
			char c;
			scanf("%c", &c);
			g[i][j] = c - 'A';
		}

	int countk = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			for(int k=i; k<n; ++k)
				for(int l=j; l<m; ++l)
				{
					int mask = set(g[k][l]);
					if(k > i)
						mask |= dp[k-1][l];
					if(l > j)
						mask |= dp[k][l-1];
					
					dp[k][l] = mask;
					
					int nbits = __builtin_popcount(mask);
					if(nbits == krec)
						++countk;
					else if(nbits > krec)
						break;
					
				}
	printf("%d\n", countk);
	
	return 0;
}