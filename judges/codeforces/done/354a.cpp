#include<cstdio>
#include<algorithm>
using namespace std;

#define INF (int) 1e9
#define MAX 100010

int main()
{
	int n, qr, ql, sumLeft[MAX], sumRight[MAX], w[MAX], l, r;

	scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
	for(int i=1; i<=n; ++i) scanf("%d", &w[i]);
	
	sumLeft[0] = sumRight[0] = 0;
	for(int i=1; i<=n; ++i)
	{
		sumLeft[i] = w[i] + sumLeft[i-1];
		sumRight[i] = w[n-i+1] + sumRight[i-1];
	}
	
	int sol = INF;
	for(int i=0; i<=n; ++i)
	{
		int s = l*sumLeft[i] + r*sumRight[n-i];
		
		if(i != n - i && !(n%2 == 1 && abs(n-2*i) == 1))
		{
			if(i > n - i) s += ql*(2*i - n - 1);
			else s += qr*(n - 2*i - 1); 
		}
		
		sol = min(sol, s);
	}
	printf("%d\n", sol);

	return 0;
}
