#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back
#define MAXN 55
#define MAXK 55
#define MAXC 105

int t, n, c, k;
double dp[MAXN][MAXC][MAXK], ps, pc;
pair<int, int> turnRange[MAXK];

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &c, &k);
		for(int i=1; i<=k; ++i)
		{
			scanf("%d %d", &turnRange[i].first, &turnRange[i].second);
			turnRange[i].first--; turnRange[i].second--;
		}
		
		for(int pos=0; pos<n; ++pos)
		{
			for(int color=0; color<c; ++color) dp[pos][color][0] = 0;
			dp[pos][1][0] = 1;
		}
		
		vector<int> before[MAXC];
		for(int color=0; color<c; ++color)
			for(int colorBefore=0; colorBefore<c; ++colorBefore)
				for(int paintedColor=0; paintedColor<c; ++paintedColor)
					if((colorBefore * paintedColor)%c == color)
						before[color].pb(colorBefore);

		ps = 0.5; pc = 1.0/(double)c;
		for(int turn=1; turn<=k; ++turn)
			for(int pos=0; pos<n; pos++)
				for(int color=0; color<c; ++color)
				{
					double &state = dp[pos][color][turn];

					if(pos > turnRange[turn].second || pos < turnRange[turn].first)
					{
						state = dp[pos][color][turn - 1];
						continue;
					}

					if(color == 0)
					{
						state = dp[pos][0][turn - 1];
						for(int color2=1; color2<c; ++color2) state += dp[pos][color2][turn-1] * ps * pc;
					}
					else
					{
						state = dp[pos][color][turn - 1] * (1 - ps);

						for(int i=0; i<(int)before[color].size(); ++i) state += dp[pos][before[color][i]][turn - 1] * ps * pc;
					}
				}
		
		double sol = 0;
		for(int pos=0; pos<n; ++pos)
			for(int color=1; color<c; ++color)
				sol += color * dp[pos][color][k];

		printf("%.7lf\n", sol);
	}

	return 0;
}
