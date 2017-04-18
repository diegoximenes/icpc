#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 2
#define MOD 1000000007
#define ll long long int

void mulMatrix(ll a[MAX][MAX], ll b[MAX][MAX], ll res[MAX][MAX], int n)
{
	int k;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(res[i][j] = k = 0; k<n; ++k)
				res[i][j] = (res[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
}

void powMatrix(ll base[MAX][MAX], int e, ll res[MAX][MAX], int n)
{
	ll temp[MAX][MAX], temp2[MAX][MAX];

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			if(e == 1)
				res[i][j] = base[i][j];
			else
				res[i][j] = (i==j);
		}
	if(e==0 || e==1)
		return;
	
	powMatrix(base, e/2, temp, n);
	mulMatrix(temp, temp, temp2, n);
	if(e%2 != 0)
		mulMatrix(base, temp2, res, n);
	else
		memcpy(res, temp2, sizeof(ll)*n*n);
}

int main()
{
	int t, n, m;
	ll sum, fibn, fibm, res[MAX][MAX], fib[MAX][MAX] = {{1, 1}, {1, 0}};
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		--n;
		m += 2; n += 2;
		powMatrix(fib, n, res, MAX);
		fibn = res[0][1] - 1;
		if(m == n+1)
			fibm = res[0][0];
		else if(m == n-1)
			fibm = res[1][1];
		else
		{
			powMatrix(fib, m, res, MAX);
			fibm = res[0][1];
		}
		sum = (fibm-1-fibn)%MOD;
		if(sum < 0)
			sum += MOD;
		printf("%lld\n", sum%MOD);
	}

	return 0;
}
