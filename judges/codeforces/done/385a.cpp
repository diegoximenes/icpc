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
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 105

int main()
{
	int n, c, v[MAX];	
	
	int sol = -INF;
	scanf("%d %d", &n, &c);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &v[i]);
		if(i >= 1) sol = max(sol, v[i-1] - v[i] - c);
	}

	printf("%d\n", max(sol, 0));

	return 0;
}
