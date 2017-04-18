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
#define INF 1e9
#define EPS 1e-9
#define MAX 105

int main()
{
	int n, m, v[MAX];
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);	
	
	int last;
	while(1)
	{
		bool end = 1;
		for(int i=0; i<n; ++i)
		{
			if(v[i]) last = i, v[i] -= min(v[i], m), end = 0;
		}
		if(end) break;
	}

	printf("%d\n", last + 1);

	return 0;
}
