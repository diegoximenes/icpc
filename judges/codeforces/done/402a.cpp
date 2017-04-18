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
	int k, a, b, v, cnt = 0;
	
	scanf("%d %d %d %d", &k, &a, &b, &v);
	
	while(a > 0)	
	{
		cnt++;
		int sections = min(b+1, k);
		b -= sections - 1;
		a -= sections*v;
	}

	printf("%d\n", cnt);

	return 0;
}
