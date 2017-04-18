#include<bits/stdc++.h>
using namespace std;

#define MAX 405

double dp[MAX][MAX];

double opt(int n, int maxExpectedTime)
{
	if(maxExpectedTime < 0) return 0.0;
	if(n == 0) return 1.0;
	double &state = dp[n][maxExpectedTime];
	if(state > -1) return state; 
	
	state = 0;
	for(int i=1; i<=n; ++i)
		state += 1.0/(double)n * opt(i-1, maxExpectedTime-1) * opt(n-i, maxExpectedTime-1);;

	return state;
}

int main()
{
	int n;
	
	scanf("%d", &n);
	for(int i=0; i<MAX; ++i)
		for(int j=0; j<MAX; ++j)
			dp[i][j] = -1;
	
	double sol = 10.0 * opt(n-2, 0);
	/*
	A : maxExpectedTime <= i
	B : maxExpectedTime <= i-1, Bc(complementar) : maxExpectedTime >= i
	P(A uniao Bc) = P(A) + P(Bc) - P(A intersecao Bc) = 1 (B esta contido em A)
	P(Bc) = 1 - P(B)
	P(A intersecao Bc) = P(A) - P(B)
	*/
	for(int i=0; i<=n-2; ++i) sol += (i*10.0)*(opt(n-2, i) - opt(n-2, i-1));

	printf("%.7lf\n", sol);

	return 0;
}