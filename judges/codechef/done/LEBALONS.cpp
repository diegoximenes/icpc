#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 45
#define fi first
#define se second
#define mp make_pair

ll dp[MAX][MAX][MAX], dp2[MAX][MAX][MAX];
int n, m, useInd;
pair<int, int> ballon[MAX];

ll opt(int i, int lastColor, int cntColors)
{
	if(i == n) return (cntColors >= m);	
	ll &state = dp[i][lastColor][cntColors];
	if(state != -1) return state;
	
	state = 0;	
	if(i != useInd) state = opt(i+1, lastColor, cntColors);
	if(lastColor == ballon[i].fi) state += opt(i+1, lastColor, cntColors);
	else state += opt(i+1, ballon[i].fi, cntColors+1);

	return state;
}

ll opt2(int i, int lastColor, int cntColors)
{
	if(i == n) return (cntColors >= m);	
	ll &state = dp2[i][lastColor][cntColors];
	if(state != -1) return state;
	
	state = opt2(i+1, lastColor, cntColors);
	if(lastColor == ballon[i].fi) state += opt2(i+1, lastColor, cntColors);
	else state += opt2(i+1, ballon[i].fi, cntColors+1);

	return state;
}

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		set<int> colors;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) scanf("%d %d", &ballon[i].fi, &ballon[i].se), colors.insert(ballon[i].fi);
		sort(ballon, ballon+n);
		
		memset(dp2, -1, sizeof(dp2));

		long double sol = 0;
		for(int b=0; b<n; ++b)
		{
			memset(dp, -1, sizeof(dp));

			useInd = b;
			sol += (long double)ballon[b].se * (long double)opt(0, 0, 0)/(long double)opt2(0, 0, 0);
		}
		
		printf("%.9Lf\n", sol);
	}

	return 0;
}
