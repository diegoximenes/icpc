#include<cstdio>
#include<cmath>
using namespace std;

#define MAX 10000

int main()
{
	int n, m, k, l[MAX+10];
	bool hasSolution = 0;

	scanf("%d %d %d", &m, &n, &k);
	for(int i=1; i<=MAX; ++i)
	{
		l[i] = 0;
		int upper = sqrt(i);
		for(int j=1; j<=upper; ++j)
			if(i%j == 0)
				++l[i];
		if(i-k > 0 && l[i] == n && l[i-k] == m)
		{
			printf("%d\n", i);
			hasSolution = 1;
			break;
		}
	}
	if(!hasSolution) puts("0");
		
	return 0;
}

