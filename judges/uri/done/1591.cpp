#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define EPS 1e-7
#define MAX 55

char g[MAX][MAX], word[MAX];

int main()
{
	int n, m, t, p;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) scanf(" %s ", g[i]);
	
		scanf("%d", &p);
		while(p--)
		{
			int cnt = 0;
			scanf(" %s ", word);
			int len = strlen(word);
			
			for(int i=0; i<n; ++i)
				for(int j=0; j<m; ++j)
				{
					for(int k=0; k<len && j+k<m; ++k)
					{
						if(word[k] != g[i][j+k]) break;
						else if(k == len-1) cnt++;
					}
				}
			
			if(len != 1)
			{
				for(int j=0; j<m; ++j)
					for(int i=0; i<n; ++i)
					{
						for(int k=0; k<len && i+k<n; ++k)
						{
							if(word[k] != g[i+k][j]) break;
							else if(k == len-1) cnt++;
						}
					}
			}
			
			printf("%d\n", cnt);
		}
	}

	return 0;
}
