#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define MAX 10100

int dp[MAX], k, d;
bool solved = 0;

int dr(int i)
{
	if(i<10) return dp[i] = i;
	else
	{
		int iaux = i;
		int n = 0;
		while(iaux != 0)
		{
			n += iaux%10;
			iaux /= 10;
		}
		return dp[i] = dr(n);
	}
}

int main()
{
	for(int i=0; i<MAX; ++i) dp[i] = dr(i);
	
	scanf("%d %d", &k, &d);
	/*for(int i=0; i<=9000; ++i)
		if(dp[i] == d && 9*k>=i)
		{
			int count9 = i/9, otherd = i%9;
			for(int j=0; j<count9; ++j, --k) putchar('9');
			if(k > 0) printf("%d", otherd), --k;
			for(int j=0; j<k; ++j) putchar('0');
			puts("");
			solved = 1;
			break;
		}
	*/
	if(k > 1 && d == 0) puts("No solution");
	else
	{
		printf("%d", d);
		for(int i=1; i<k; ++i) putchar('0');
		puts("");
	}

	return 0;
}
