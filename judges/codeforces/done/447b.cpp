#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
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
#define EPS 1e-9
#define MAX 1005

char s[MAX];

int main()
{
	scanf(" %s ", s);
	int n = strlen(s), k, w[30];
	scanf("%d", &k);

	int maxw = 0;
	for(int i=0; i<26; ++i) scanf("%d", &w[i]), maxw = max(maxw, w[i]);

	int sol = 0;
	for(int i=0; i<n; ++i) sol += w[s[i] - 'a'] * (i+1);
	for(int i=n; i<n+k; ++i) sol += maxw * (i+1);

	printf("%d\n", sol);

	return 0;
}
