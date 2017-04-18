#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define MAX 1100

int main()
{
	int n, m, k, deg[MAX], u, v;

	while(scanf("%d %d", &k, &m) && k)
	{
		bool no = 0;
		n = ceil(log(k)/log(2));
		
		int p = pow(2, n);
		if(p != k) no = 1;
		
		for(int i=0; i<=k; ++i) deg[i] = n;

		while(m--)
		{
			scanf("%d %d", &u, &v);
			if(no) continue;
			
			int powed = pow(2, n);
			if(u < 0 || v < 0 || u >= powed || v >= powed) no = 1;

			int xored = u^v, count = 0;
			for(int i=0; i<32 && count < 2; ++i) if((1 << i) & xored) ++count;
			if(count != 1) no = 1;
			deg[u]--; deg[v]--;
			if(deg[u] < 0 || deg[v] < 0) no = 1;
		}
		for(int i=0; i<k && !no; ++i)
			if(deg[i] != 0)
				no = 1;
				
		if(no) puts("NO");
		else puts("YES");
	}


	return 0;
}
