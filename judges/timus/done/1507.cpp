#include<cstdio>
using namespace std;

#define MAX 55

void mulMatrix(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int n)
{
	int k;
	for(int i = 0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(c[i][j] = k = 0; k<n; ++k)
			{
				c[i][j] += a[i][k]*b[k][j];
				if(c[i][j] > 0)
					c[i][j] = 1;
			}
}

void powMatrix(int base[MAX][MAX], int e, int r[MAX][MAX], int n)
{
	int temp[MAX][MAX], temp2[MAX][MAX];
	
	for(int i = 0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			if(e == 1)
				r[i][j] = base[i][j];
			else
				r[i][j] = (i == j);	
		}
	if(e == 0 || e == 1)
		return;
	
	powMatrix(base, e/2, temp, n);
	mulMatrix(temp, temp, temp2, n);
	if(e%2 != 0)
		mulMatrix(base, temp2, r, n);
	else
	{
		for(int i = 0; i<n; ++i)
			for(int j=0; j<n; ++j)
				r[i][j] = temp2[i][j];
	}
}

void sumMatrix(int a[MAX][MAX], int b[MAX][MAX], int n)
{
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			a[i][j] = a[i][j] + b[i][j];
			if(a[i][j] > 0)
				a[i][j] = 1;
		}
}

int main()
{
	int n, m[MAX][MAX], temp[MAX][MAX], res[MAX][MAX];
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			res[i][j] = 0;
			scanf("%d", &m[i][j]);
			if(m[i][j] > 0)
				m[i][j] = 1;
		}
	
	for(int i=n*(n-1); i<=n*(n+1); ++i)
	{
		powMatrix(m, i, temp, n);
		sumMatrix(res, temp, n);
	}
	
	bool printed = 0;
	for(int i=0; !printed && i<n; ++i)
		for(int j=0; !printed && j<n; ++j)
			if(res[i][j] == 0)
			{
				printed = 1;
				puts("No");
			}
	if(!printed)
		puts("Yes");
	return 0;
}