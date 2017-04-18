#include<cstdio>
using namespace std;

#define ll long long

ll fib[1000000];

int fibo()
{
	fib[0] = fib[1] = 1;
	for(int i=2; ;++i)
	{
		fib[i] = fib[i-1] + fib[i-2];
		if(fib[i] > 2000000000)
			return i-1;
	}
}

int main()
{
	int t, countFib = fibo(), n, w;
	
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		ll count = 1;
		scanf("%d", &n);
		while(n--)
		{
			int auxCount = 0;
			scanf("%d", &w);
			for(int j=countFib; j>=0 && w!=0; --j)
				if(fib[j] <= w)
				{
					w -= fib[j];
					++auxCount;
				}
			count *= auxCount;
		}
		
		printf("Case %d: %lld\n", tc, count);
	}

	return 0;
}
