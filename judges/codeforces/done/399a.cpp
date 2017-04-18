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

int main()
{
	int n, p, k;
	
	scanf("%d %d %d", &n, &p, &k);
	int upper = min(p+k, n), lower = max(1, p-k);
	bool first = 1;
	if(lower != 1) printf("<<"), first = 0;
	for(int i=lower; i<=upper; ++i)
	{
		if(!first) putchar(' ');
		if(i == p) printf("(%d)", i);
		else printf("%d", i);
		first = 0;
	}
	if(upper != n) printf(" >>");
	puts("");
	return 0;
}
