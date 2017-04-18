#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int t, u, v;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &u, &v);

		int len = 0, hu, hv;
			
		for(hu=0; (1 << hu) <= u; ++hu);
		for(hv=0; (1 << hv) <= v; ++hv);
		--hu; --hv;

		if(hv > hu) swap(hu, hv), swap(u, v);
		while(hu != hv) hu--, len++, u /= 2;
		while(u != v) u /= 2, v /= 2, len += 2;

		printf("%d\n", len);
	}

	return 0;
}
