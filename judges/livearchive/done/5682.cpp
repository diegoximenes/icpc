#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 55

int main()
{
	int tc, v[MAX], n;

	scanf("%d", &tc);
	for(int t=1; t<=tc; ++t)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i) scanf("%d", &v[i]);

		sort(v, v+n);
		int maxgap = 0;
		for(int i=1; i<n; ++i) maxgap = max(maxgap, v[i] - v[i-1]);
		
		printf("Class %d\nMax %d, Min %d, Largest gap %d\n", t, v[n-1], v[0], maxgap);
	}

	return 0;
}
