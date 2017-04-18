#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 105

int main()
{
	int t, n, x, op, v[MAX];

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &x, &op);
		for(int i=0; i<n; ++i) v[i] = i+1;

		if(op == 1)
		{
			if(x <= n)
				for(int i=x-1; i<n; ++i) 
					v[i] = i+2;
		}
		else
		{
			if(x > n) v[n-1] = x;
		}

		printf("%d", v[0]);
		for(int i=1; i<n; ++i) printf(" %d", v[i]);
		puts("");
	}

	return 0;
}
