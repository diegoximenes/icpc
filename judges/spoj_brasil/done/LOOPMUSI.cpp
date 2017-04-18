#include<cstdio>
using namespace std;

#define MAX 10000+10

int main()
{
	int n, v[MAX];

	while(scanf("%d", &n) && n)
	{
		for(int i=1; i<=n; ++i)
			scanf("%d", &v[i]);
		v[0] = v[n]; v[n+1] = v[1];

		int count = 0;
		for(int i=1; i<n+1; ++i)
			if((v[i] > v[i-1] && v[i] > v[i+1]) || (v[i] < v[i-1] && v[i] < v[i+1]))
				++count;
		printf("%d\n", count);
	}

	return 0;
}
