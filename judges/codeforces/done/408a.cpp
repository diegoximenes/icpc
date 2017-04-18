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

#define MAX 105

int main()
{
	int n, k[MAX], m, sol = INF;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &k[i]);
	for(int i=0; i<n; ++i)
	{
		int lsol = 0;
		for(int j=0; j<k[i]; ++j)
		{
			scanf("%d", &m);
			lsol += m*5 + 15;
		}
		sol = min(sol, lsol);
	}
	printf("%d\n", sol);

	return 0;
}
