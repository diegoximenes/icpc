#include<cstdio>
#include<cstring>
using namespace std;

typedef unsigned long long ull;
#define MAX 2
#define MOD 1000000

void mulMatrix(ull a[MAX][MAX], ull b[MAX][MAX], ull c[MAX][MAX], int n)
{
	ull k;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(c[i][j] = k = 0; k<(ull)n; ++k)
				c[i][j] = (c[i][j] + (a[i][k]*b[k][j])%MOD)%MOD;
}

void powMatrix(ull b[MAX][MAX], ull r[MAX][MAX], int n, ull e)
{
	ull temp[MAX][MAX];

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			r[i][j] = (i == j);

	if(!e) return;
	powMatrix(b, temp, n, e/2);
	mulMatrix(temp, temp, r, n);
	if(e%2 != 0)
	{
		mulMatrix(b, r, temp, n);
		memcpy(r, temp, sizeof(temp));
	}	
}

int main()
{
	ull n, k, l;

	while(scanf("%lld %lld %lld", &n, &k, &l) == 3)
	{
		ull m[2][2] = {{k%MOD, l%MOD}, {1, 0}}, r[2][2];
		powMatrix(m, r, 2, n/5 - 1);
		printf("%06lld\n", ((r[0][0]*(k%MOD))%MOD + r[0][1])%MOD);
	}

	return 0;
}
