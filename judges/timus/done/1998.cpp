#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 100005

int w[MAX], cum[MAX];

int main()
{
	int n, m, k, t;
	
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; ++i) scanf("%d", &w[i]);
	
	cum[0] = 0;
	cum[n] = w[n];
	for(int i=n-1; i>=0; --i) cum[i] = cum[i+1] + w[i];
	
	int sol = 0, lastt = 0, pos = 0;
	for(int i=0; i<m; ++i)
	{
		scanf("%d", &t);

		int nextpos = pos + (t - lastt);
		if(nextpos > n)
		{
			sol += n - pos;
			pos = n;
			break;
		}

		pos = nextpos;
		sol += t - lastt;
		
		int l = 1, r = pos-1, lastcan = -1;
		while(l <= r)
		{
			int mid = (l + r)/2;

			if(cum[mid] - cum[pos] > k) lastcan = mid, l = mid + 1;
			else r = mid - 1;
		}
		pos = max(lastcan-1, 0);
		lastt = t;
	}
	sol += n - pos;
	
	printf("%d\n", sol);

	return 0;
}
