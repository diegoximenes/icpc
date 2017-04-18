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
#define MAX 1005

int main()
{
	char s1[MAX], s2[MAX];
	int cnt1[30], cnt2[30];
	
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));

	scanf(" %s %s ", s1, s2);
	int len1 = strlen(s1), len2 = strlen(s2);
	
	for(int i=0; i<len1; ++i) cnt1[s1[i] - 'a']++;
	for(int i=0; i<len2; ++i) cnt2[s2[i] - 'a']++;
	
	double sol = 0;
	for(char c='a'; c<='z'; ++c)
	{
		if(cnt1[c - 'a'] == 0 && cnt2[c - 'a'] > 0 )
		{
			puts("-1");
			return 0;
		}
		if(cnt1[c - 'a'] >= cnt2[c - 'a']) sol += cnt2[c - 'a'];
		else sol += cnt1[c - 'a'];
	}
	
	printf("%d\n", (int)sol);

	return 0;
}
