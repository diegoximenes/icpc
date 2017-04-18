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

int main()
{
	int n, diag[MAX], q, x, cntDiag = 0;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			scanf("%d", &x);
			if(i == j) cntDiag += x, diag[i] = x;
		}
	
	scanf("%d", &q);
	for(int i=0; i<q; ++i)
	{
		scanf("%d", &x);
		if(x == 3) printf("%d", cntDiag%2);
		else
		{
			scanf("%d", &x);
			if(diag[x]) diag[x] = 0, cntDiag--;
			else diag[x] = 1, cntDiag++;
		}
	}
	puts("");

	return 0;
}
