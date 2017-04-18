#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 10010

int n, dp[MAX], p[MAX], valDay[6];
vector< pair< pair<int, int>, int> > interval;
vector< pair<int, int> > start, finish;

int opt(int i)
{
	if(i == -1) return 0;
	if(dp[i] != -1) return dp[i];

	return dp[i] = max(interval[i].second + opt(p[i]), opt(i - 1));
}

inline int minToDay(int m)
{
	int minDay = 24*60;
	if(m < minDay) return 0;
	else if(m < 2*minDay) return 1;
	else if(m < 3*minDay) return 2;
	else if(m < 4*minDay) return 3;
	else return 4;
}

void reconstruct(int i)
{
	if(i == -1) return;
	if(opt(i) == interval[i].second + opt(p[i]))
	{
		valDay[minToDay(interval[i].first.first)] += interval[i].second;
		reconstruct(p[i]);
	}
	else reconstruct(i - 1);	
}

int main()
{
	int v, hs, ms, hf, mf, d;
	char day[5];

	while(scanf("%d", &n) && n)
	{
		interval.clear();
		start.clear();
		finish.clear();
		memset(dp, -1, sizeof(dp));
		memset(p, -1, sizeof(p));
		memset(valDay, 0, sizeof(valDay));

		for(int i=0; i<n; ++i)
		{
			scanf("%*d %d %s %d:%d %d:%d", &v, day, &hs, &ms, &hf, &mf);

			if(strcmp(day, "Seg") == 0) d = 0;
			else if(strcmp(day, "Ter") == 0) d = 1;
			else if(strcmp(day, "Qua") == 0) d = 2;
			else if(strcmp(day, "Qui") == 0) d = 3;
			else if(strcmp(day, "Sex") == 0) d = 4;
			else if(strcmp(day, "Sab") == 0) d = 5;
			
			int ts = d*24*60 + 60*hs + ms, tf = d*24*60 + 60*hf + mf;
			interval.pb(mp(mp(tf, ts), v));
		}
		
		sort(interval.begin(), interval.end());
		for(int i=0; i<n; ++i)
		{
			start.pb(mp(interval[i].first.second, i));
			finish.pb(mp(interval[i].first.first, i));
		}
		sort(start.begin(), start.end());

		int i=0, j=0;
		while(i<n && j<n)
		{
			if(finish[i].first <= start[j].first) 
				++i;
			else 
			{
				if(i-1 < 0) p[j] = -1;
				else p[start[j].second] = finish[i-1].second;
				++j;
			}
		}
		
		int sol = opt(n-1);
		reconstruct(n-1);
		printf("Total de pontos: %d\n", sol);
		printf("Seg: %d\n", valDay[0]);
		printf("Ter: %d\n", valDay[1]);
		printf("Qua: %d\n", valDay[2]);
		printf("Qui: %d\n", valDay[3]);
		printf("Sex: %d\n", valDay[4]);
	}

	return 0;
}

