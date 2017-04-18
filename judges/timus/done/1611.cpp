#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define NMAX 10005
#define KMAX 55
#define INF 0x3f3f3f3f

int dp[NMAX][KMAX], n, k;
char s[NMAX];

int opt(int i, int j)
{
	if(i == n) return 0;
	int &state = dp[i][j];
	if(state != -1) return state;
	
	int sol = INF;
	if(j < k)
	{
		if((i+j+1)%10 == 0) sol = min(sol, 1 + opt(i, j+1));
		else sol = min(sol, opt(i, j+1));
	}
	if((i+j+1)%10 == 0)
	{
		if(s[i] == '1') sol = min(sol, 1 + opt(i+1, j));
		else sol = min(sol, opt(i+1, j));
	}
	else sol = min(sol, opt(i+1, j));
	
	return state = sol;
}

vector<int> out;
void build(int i, int j)
{
	if(i == n) return;
	
	if(j < k)
	{
		if((i+j+1)%10 == 0)
		{
			if(opt(i, j) == 1 + opt(i, j+1))
			{
				out.pb(i+j+1);
				build(i, j+1);
				return;
			}
		}
		else if(opt(i, j) == opt(i, j+1))
		{
			out.pb(i+j+1);
			build(i, j+1);
			return;
		}
	}
	
	build(i+1, j);
}

int main()
{
	scanf("%d %d %s ", &n, &k, s);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", opt(0, 0));
	
	build(0, 0);	
	printf("%d", (int)out.size());
	for(int i=0; i<(int)out.size(); ++i) printf(" %d", out[i]);
	puts("");

	return 0;
}
