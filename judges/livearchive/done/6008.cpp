#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 1005
#define INF (int) 1e9

int v1[MAX], v2[MAX];

int main()
{
	int tc, n1, n2;

	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n1);
		for(int i=0; i<n1; ++i) scanf("%d", &v1[i]);
		scanf("%d", &n2);
		for(int i=0; i<n2; ++i) scanf("%d", &v2[i]);
		
		int mindist = INF;
		for(int i=0; i<n1 && mindist > 0; ++i)
			for(int j=0; j<n2 && mindist > 0; ++j)
				mindist = min(mindist, abs(v1[i] - v2[j]));
		printf("%d\n", mindist);
	}

	return 0;
}
