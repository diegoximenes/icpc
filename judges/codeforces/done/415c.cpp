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
#define EPS 1e-9
#define MAX 1000000000

int main()
{
	int n, k;
	vector<int> out;

	scanf("%d %d", &n, &k);

	if(n == 1 && k == 0)
	{
		puts("1");
		return 0;
	}
	if(k < n/2 || n == 1)
	{
		puts("-1");
		return 0;
	}
	
	int d = k/(n/2), i, j = 0, aux = 0;
	
	if(k%(n/2) > 0)
	{
		out.pb(d + k%(n/2)); out.pb(2*(d + k%(n/2)));
		aux = 1;
		while(j <= 2*(d + k%(n/2))) j += d;
	}
	else j = d;

	for(i=0; i<n/2-aux; ++i, j+=2*d) out.pb(j), out.pb(j+d);

	if(n%2 != 0)
	{
		int back = out.back();
		out.pb(back + 1);
	}
	
	if(out.back() > MAX) puts("-1");
	else
	{
		printf("%d", out[0]);
		for(int i=1; i<(int)out.size(); ++i) printf(" %d", out[i]);
		puts("");
	}

	return 0;
}
