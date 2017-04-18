#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 200010
#define INF 1200000000

int v[MAX], n, lenStart[MAX], lenEnd[MAX], bestEnd[MAX];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", &v[i]);
	
		lenEnd[1] = 1;
		for(int i=2; i<=n; ++i)
		{
			if(v[i] > v[i-1]) lenEnd[i] = lenEnd[i-1] + 1;
			else lenEnd[i] = 1;
		}
		lenStart[n] = 1;
		for(int i=n-1; i>=1; --i)
		{
			if(v[i] < v[i+1]) lenStart[i] = lenStart[i+1] + 1;
			else lenStart[i] = 1;
		}

		for(int i=1; i<=n; ++i) bestEnd[i] = INF;
		int maxlen = -1, sol = 1;
		for(int i=1; i<=n; ++i)
		{
			bestEnd[lenEnd[i]] = min(bestEnd[lenEnd[i]], v[i]);

			maxlen = max(maxlen, lenEnd[i]);
			int l = 1, r = maxlen, lastcan = -1;
			while(l <= r)
			{
				int mid = (l + r)/2;
				
				if(bestEnd[mid] < v[i]) lastcan = mid, l = mid + 1;
				else r = mid - 1;
			}
			
			sol = max(sol, lastcan + lenStart[i]);
		}
		
		printf("%d\n", sol);
	}

	return 0;
}
