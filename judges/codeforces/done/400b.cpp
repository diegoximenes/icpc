#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
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
#define INF 1e9
#define MAX 1005

int main()
{
	int n, m, g, s;
	char line[MAX];
	set<int> tree;
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) 
	{
		scanf(" %s", line);
		for(int j=0; j<m; ++j)
		{
			if(line[j] == 'G') g = j;
			else if(line[j] == 'S') s = j;
		}
		
		tree.insert(s - g);
		
		if(g > s)
		{
			puts("-1");
			return 0;
		}
	}
	
	printf("%d\n", (int)tree.size());

	return 0;
}
