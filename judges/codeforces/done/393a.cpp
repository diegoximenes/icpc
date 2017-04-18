#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9

int main()
{
	char s[200];
	int cnt[30];

	scanf(" %s", s);
	int n = strlen(s), sol = 0;
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<n; ++i)
		cnt[s[i] - 'a']++;
		
	if(cnt['n' - 'a'] >= 3) 
	{
		sol = min(1, cnt['e' - 'a']/3);
		sol = min(sol, min(cnt['i' - 'a'], cnt['t' - 'a']));
		cnt['n' - 'a'] -= 3;
		cnt['i' - 'a'] -= 1;
		cnt['t' - 'a'] -= 1;
		cnt['e' - 'a'] -= 3;
	}
	if(sol >= 1)
	{
		int sol2 = min(cnt['n' - 'a']/2, cnt['e' - 'a']/3);
		sol += min(sol2, min(cnt['i' - 'a'], cnt['t' - 'a']));
	}

	printf("%d\n", sol);

	return 0;
}
