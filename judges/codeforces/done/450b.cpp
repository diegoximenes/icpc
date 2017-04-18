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
#define MAX 2
#define MOD (ll) 1000000007

void mulMatrix(ll a[MAX][MAX], ll b[MAX][MAX], ll c[MAX][MAX], int n)
{
	int k;
	for(int i = 0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(c[i][j] = k = 0; k<n; ++k)
			{
				ll aux = (a[i][k]*b[k][j])%MOD;
				if(aux < 0) aux += MOD;

				c[i][j] = (c[i][j] + aux)%MOD;
				if(c[i][j] < 0) c[i][j] += MOD;
			}
}

void powMatrix(ll base[MAX][MAX], ll e, ll r[MAX][MAX], int n)
{
	ll temp[MAX][MAX], temp2[MAX][MAX];
	
	for(int i = 0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			if(e == 1) r[i][j] = base[i][j];
			else r[i][j] = (i == j);	
		}
	if(e == 0 || e == 1) return;
	
	powMatrix(base, e/2, temp, n);
	mulMatrix(temp, temp, temp2, n);
	if(e%2 != 0) mulMatrix(base, temp2, r, n);
	else memcpy(r, temp2, sizeof(temp2));
}

int main()
{
	ll x, y, n;
	ll a[MAX][MAX] = {{1, -1 + MOD}, {1, 0}}, b[MAX][MAX];

	cin >> x >> y >> n;
	
	ll sol = 0;
	if(n > 2)
	{
		powMatrix(a, n-2, b, 2);
		sol = (b[0][0]*y)%MOD;
		
		if(sol < 0) sol += MOD;
		sol = (sol + (b[0][1]*x)%MOD)%MOD;
	}
	else if(n == 1) sol = x;
	else sol = y;
	
	if(sol < 0) sol += MOD;
	cout << sol << endl;
	
	return 0;
}
