#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 25

int main()
{
	int n, b, bank[MAX];

	while(scanf("%d %d", &b, &n) && b)
	{
		memset(bank, 0, sizeof(bank));
		for(int i=0; i<b; ++i)
			scanf("%d", &bank[i]);
		for(int i=0; i<n; ++i)
		{
			int b1, b2, v;
			scanf("%d %d %d", &b1, &b2, &v);
			--b1, --b2;
			bank[b1] -=v; bank[b2] += v;
		}

		bool no = 0;
		for(int i=0; i<b; ++i)
			if(bank[i] < 0)
			{
				no = 1;
				break;
			}
		if(no) puts("N");
		else puts("S");
	}

	return 0;
}
