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
#define MAX 305

int main()
{
	int n, p;
	set<int> tree;
	
	scanf("%d %d", &p, &n);
	bool printed = 0;
	for(int i=0; i<n; ++i)
	{
		int x;
		scanf("%d", &x);
		if(tree.find(x%p) != tree.end() && !printed) printf("%d\n", i+1), printed = 1;
		else tree.insert(x%p);
	}
	if(!printed) puts("-1");

	return 0;
}
