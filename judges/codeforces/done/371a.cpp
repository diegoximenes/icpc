#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 105

int main()
{
	int n, k, x, count[2][MAX];
	
	memset(count, 0, sizeof(count));
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &x);
		count[x-1][i%k]++;
	}

	int sol = 0;
	for(int i=0; i<k; ++i) sol += min(count[0][i], count[1][i]);
	printf("%d\n", sol);

	return 0;
}
