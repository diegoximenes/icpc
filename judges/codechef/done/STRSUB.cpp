#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005

char s[MAX];
ll cnt0[MAX], cnt1[MAX], cum[MAX];
int last[MAX];
int t, n, k, q;

int main()
{

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d \n", &n, &k, &q);
		for(int i=1; i<=n; ++i) s[i] = getchar();
			
		cnt0[0] = cnt1[0] = 0;
		for(int i=1; i<=n; ++i)
		{
			cnt0[i] = cnt0[i-1];
			cnt1[i] = cnt1[i-1];
			if(s[i] == '0') cnt0[i]++;
			else cnt1[i]++;

			int l = 1, r = i, lastcan = i;
			while(l <= r)
			{
				int mid = (l + r)/2;
				if(cnt0[i] - cnt0[mid-1] <= k && cnt1[i] - cnt1[mid-1] <= k) r = mid - 1, lastcan = mid;
				else l = mid + 1;
			}
			last[i] = lastcan;

			cum[i] = cum[i-1];
			cum[i] += i - last[i] + 1;
		}
				
		while(q--)
		{
			int a, b;
			scanf("%d %d", &a, &b);

			int l = a, r = b, lastcan = -1;
			while(l <= r)
			{
				int mid = (l + r)/2;
				if(last[mid] < a) l = mid + 1, lastcan = mid;
				else r = mid - 1;
			}
			
			ll sol = cum[b] - cum[a-1];
			if(lastcan != -1)
			{
				sol = sol - cum[lastcan] + cum[a-1];
				sol += 1LL*(1 + lastcan-a+1)*(lastcan-a+1)/2;
			}

			printf("%lld\n", sol);	
		}
	}

	return 0;
}
