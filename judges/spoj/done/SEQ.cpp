#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 11
#define MOD 1000000000
#define ll long long

void mul(ll a[MAX][MAX], ll b[MAX][MAX], ll res[MAX][MAX], int n)
{
	int k;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(k = res[i][j] = 0; k<n; ++k)
				res[i][j] = (res[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
}

void exp(ll base[MAX][MAX], int e, ll res[MAX][MAX], int n)
{
	ll temp[MAX][MAX], temp2[MAX][MAX];

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			if(e == 1)
				res[i][j] = base[i][j];
			else
				res[i][j] = (i == j);
		}
	if(e==0 || e==1)
		return;
	
	exp(base, e/2, temp, n);
	mul(temp, temp, temp2, n);
	if(e%2 != 0)
		mul(base, temp2, res, n);
	else
		memcpy(res, temp2, sizeof(temp2));
}

int main()
{
	int t, n, k;
	ll a[MAX], c[MAX], mat[MAX][MAX], res[MAX][MAX];

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &k);
		for(int i=0; i<k; ++i)
		{
			scanf("%lld", &a[i]);
			a[i] %= MOD;
		}
		for(int i=0; i<k; ++i)
		{
			scanf("%lld", &c[i]);
			c[i] %= MOD;
		}
		scanf("%d", &n);

		if(n > k)
		{
			memset(mat, 0, sizeof(mat));
			for(int i=0; i<k; ++i)
				mat[0][i] = c[i];
			for(int i=1; i<k; ++i)
				mat[i][i-1] = 1;
			exp(mat, n-k, res, k);
			
			ll sol = 0;
			for(int i=0; i<k; ++i)
				sol = (sol + (res[0][i]*a[k-i-1])%MOD)%MOD;
			printf("%lld\n", sol);
		}
		else
			printf("%lld\n", a[n-1]);
	}

	return 0;
}
