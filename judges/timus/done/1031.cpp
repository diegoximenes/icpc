#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 10005

int dp[MAX], v[MAX], d[4], c[4], n, s, t;

int opt(int i)
{
	if(i >= t) return 0;
	int &state = dp[i];
	if(state != -1) return state;
	
	int sol = INF;
	for(int j=0; j<3; ++j)
	{
		int l = i+1, r = n-1, lastcan = -1;
		while(l <= r)
		{
			int mid = (l + r)/2;
			if(v[mid] - v[i] > d[j]) r = mid - 1;
			else lastcan = mid, l = mid + 1;
		}
	
		int lastd = 0;
		if(j > 0) lastd = d[j-1];
		if(lastcan != -1 && v[lastcan] - v[i] > lastd) sol = min(sol, c[j] + opt(lastcan));
	}

	return state = sol;
}

int main()
{
	for(int i=0; i<3; ++i) scanf("%d", &d[i]);
	for(int i=0; i<3; ++i) scanf("%d", &c[i]);
	scanf("%d %d %d", &n, &s, &t);
	--s; --t; if(s > t) swap(s, t);
	v[0] = 0;
	for(int i=1; i<n; ++i) scanf("%d", &v[i]);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", opt(s));

	return 0;
}
