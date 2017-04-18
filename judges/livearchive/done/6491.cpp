#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 19
#define MASKMAX (1 << MAX)

int n;
int dp[MASKMAX][MAX];
char s[MAX];

inline int cost(char c, char c2)
{
	int sol1 = abs(c - c2);
	int sol2 = 'Z' - c + c2 - 'A' + 1;
	int sol3 = c - 'A' + 'Z' - c2 + 1;

	return min(sol1, min(sol2, sol3));
}

int opt(int mask, int last)
{
	if(mask == (1 << n) - 1) return 0;
	int &state = dp[mask][last];
	if(state != -1) return state;
	
	char c = s[last];
	
	int pos = 0;
	for(int i=0; i<=last; ++i)
		if(mask & (1 << i))
			++pos;
	
	int dposRight[MAX], dposLeft[MAX];
	memset(dposRight, 0, sizeof(dposRight));
	memset(dposLeft, 0, sizeof(dposLeft));
	for(int j=last+1; j<n; ++j) dposRight[j] = dposRight[j-1] + ((mask & (1 << j)) != 0);
	for(int j=last-1; j>=0; --j) dposLeft[j] = dposLeft[j+1] + ((mask & (1 << j)) != 0);

	int sol = INF;
	for(int i=0; i<n; ++i)
		if((mask & (1 << i)) == 0)
		{
			int deltaPos;
			if(i > last) deltaPos = dposRight[i];
			else deltaPos = dposLeft[i] + 1;
			
			sol = min(sol, deltaPos + cost(c, s[i]) + opt(mask | (1 << i), i));
		}
	
	return state = sol;
}

int main()
{
	while(scanf(" %s ", s) && strcmp(s, "0") != 0)
	{
		n = strlen(s);
			
		int sol = INF;
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<n; ++i)
			sol = min(sol, n + cost('A', s[i]) + opt((1 << i), i));
		
		printf("%d\n", sol);
	}

	return 0;
}
