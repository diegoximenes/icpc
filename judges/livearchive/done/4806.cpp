#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAX 100

int main()
{
	int n, b, v[MAX];
	bool can[MAX], solved;

	while(scanf("%d %d", &n, &b) && n)
	{
		for(int i=0; i<b; ++i) scanf("%d", &v[i]);
		
		memset(can, 0, sizeof(can));
		for(int i=0; i<b; ++i)
			for(int j=0; j<b; ++j)
				can[abs(v[i] - v[j])] = 1;

		solved = 0;
		for(int i=0; i<=n && !solved; ++i)
			if(!can[i])
			{
				puts("N");
				solved = 1;
			}
		if(!solved) puts("Y");
	}

	return 0;
}
