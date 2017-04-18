#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 1000010

int main()
{
	int n;
	pair<int, int> v[MAX];

	while(scanf("%d", &n) == 1)
	{
		for(int i=0; i<n; ++i)
			scanf("%d %d", &v[i].second, &v[i].first);
		sort(v, v+n);

		int count = 1, r = v[0].first;
		for(int i=1; i<n; ++i)
			if(v[i].second > r)
			{
				++count;
				r = v[i].first;
			}
		printf("%d\n", count);
	}

	return 0;
}
