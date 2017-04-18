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
#define MAX 105

int main()
{
	int n, m, light[MAX], x;
	
	scanf("%d %d", &n, &m);	
	memset(light, 0, sizeof(light));
	for(int i=0; i<m; ++i)
	{
		scanf("%d", &x);
		for(int j=x; j<=n; ++j)
			if(light[j] == 0)
				light[j] = x;
	}
	
	printf("%d", light[1]);
	for(int i=2; i<=n; ++i) printf(" %d", light[i]);
	puts("");

	return 0;
}
