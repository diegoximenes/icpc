#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 100010

int main()
{
	int n, g, s, r, v[MAX];

	while(scanf("%d %d", &n, &g) == 2)
	{
		for(int i=0; i<n; ++i)
		{
			scanf("%d %d", &s, &r);
			v[i] = s - r;
		}
		sort(v, v+n);

		int pt = 0;
		for(int i=n-1; i>=0; --i)
		{
			if(v[i] > 0) pt += 3;
			else if(v[i] == 0)
			{
				if(g > 0) pt += 3, g--;
				else pt++;
			}
			else if(g == -v[i]) pt++, g -= -v[i];
			else if(g > -v[i]) pt += 3, g -= -v[i] + 1;
		}

		printf("%d\n", pt);
	}

	return 0;
}
