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

int main()
{
	int t, r1, r2;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &r1, &r2);
		printf("%d\n", r1 + r2);
	}

	return 0;
}
