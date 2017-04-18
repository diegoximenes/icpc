#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int costBus = 0, costTro = 0, rides, c1, c2, c3, c4, n, m;
	
	scanf("%d %d %d %d %d %d", &c1, &c2, &c3, &c4, &n, &m);
	for(int i=0; i<n; ++i) 
	{
		scanf("%d", &rides);
		costBus += min(c1*rides, c2);
	}
	for(int i=0; i<m; ++i) 
	{
		scanf("%d", &rides);
		costTro += min(c1*rides, c2);
	}
	
	costBus = min(c3, costBus);
	costTro = min(c3, costTro);
	printf("%d\n", min(costBus + costTro, c4));

	return 0;
}
