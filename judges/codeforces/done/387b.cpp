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
#define MAX 3005
#define MAX2 1000010

int cnt[MAX2], cum[MAX2];

int main()
{
	int n, m, a[MAX], b[MAX], maxb = -1;
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);

	for(int i=0; i<m; ++i)
	{
		scanf("%d", &b[i]);
		cnt[b[i]]++;
		maxb = max(maxb, b[i]);
	}
	
	cum[maxb] = cnt[maxb];
	for(int i=maxb-1; i>=0; --i) cum[i] = cum[i+1] + cnt[i];
	sort(a, a+n);

	int aux = 0, sol = 0;
	for(int i=n-1; i>=0; --i)
	{
		if(cum[a[i]] - aux <= 0) ++sol;
		else ++aux;

		//printf("a[i]= %d, cum[a[i]]= %d, aux= %d\n", a[i], cum[a[i]], aux);
	}

	printf("%d\n", sol);

	return 0;
}
