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
#define EPS 1e-9
#define MAX 100010

int out[MAX];

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i) out[i] = i+1;
		
	for(int i=n-k, j=k, turn=1; i<n; i++, j--, turn=1-turn) 
	{
		if(turn) out[i] = out[i-1] + j;
		else out[i] = out[i-1] - j;
	}
		
	
	printf("%d", out[0]);
	for(int i=1; i<n; ++i) printf(" %d", out[i]);
	puts("");

	return 0;
}
