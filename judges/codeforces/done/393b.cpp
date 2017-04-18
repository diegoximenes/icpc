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
#define MAX 200

int main()
{
	int n;
	double w[MAX][MAX], a[MAX][MAX], b[MAX][MAX];
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			scanf("%lf", &w[i][j]);	
			if(i == j) a[i][j] = w[i][j], b[i][j] = 0;
		}
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(i != j)
			{
				b[i][j] = -(w[j][i] - w[i][j])/2.0;
				a[i][j] = w[i][j] - b[i][j];
			}

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			printf("%.6lf", a[i][j]);
			if(j != n-1) printf(" ");
			else puts("");
		}
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			printf("%.6lf", b[i][j]);
			if(j != n-1) printf(" ");
			else puts("");
		}

	return 0;
}
