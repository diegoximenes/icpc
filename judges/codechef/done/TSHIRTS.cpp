#include<bits/stdc++.h>
using namespace std;

#define NMAX 10
#define MASKMAX (1 << NMAX)
#define TSHIRTMAX 105
#define MOD 1000000007

char line[100000];
int n, dp[MASKMAX][TSHIRTMAX], maxtshirt;
bool person[NMAX][TSHIRTMAX];

int opt(int mask, int tshirt)
{
	if(__builtin_popcount(mask) == n) return 1;
	if(tshirt == maxtshirt) return 0;
	int &state = dp[mask][tshirt];
	if(state != -1) return state;
	
	int sol = opt(mask, tshirt + 1);
	for(int i=0; i<n; ++i)
		if(!(mask & (1 << i)) && person[i][tshirt])
			sol = (sol + opt(mask | (1 << i), tshirt + 1))%MOD;
	
	return state = sol;
}

int main()
{
	int t, tshirt;

	scanf("%d", &t);
	while(t--)
	{
		memset(person, 0, sizeof(person));
		memset(dp, -1, sizeof(dp));
		maxtshirt = -1;

		scanf("%d", &n);
		gets(line);
		for(int i=0; i<n; ++i)
		{
			gets(line);
			int p = 0, k;
			while(sscanf(line + p, " %d%n", &tshirt, &k) == 1)
			{
				maxtshirt = max(maxtshirt, tshirt);
				person[i][tshirt-1] = 1;
				
				p += k;
			}
		}

		printf("%d\n", opt(0, 0));
	}

	return 0;
}
