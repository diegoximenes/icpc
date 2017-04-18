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
#define MAX 205

int main()
{
	char s[MAX];
	int k;
	
	scanf(" %s %d", s, &k);	
	int n = strlen(s);
	
	int maxl = 0;
	for(int b=0; b<n; ++b)
		for(int e=b; e<n+k; ++e)
		{
			if((e-b+1)%2 != 0) continue;

			int l = (e-b+1)/2;
			bool can = 1;
			for(int i=b; can && (i-b)<l && i<n; ++i)
			{
				if(i + l >= n) break;
				else if(s[i+l] != s[i]) can = 0;
			}
			if(can) maxl = max(maxl, l);//, printf("b= %d, e=%d, l= %d\n", b, e, l);
		}
	
	printf("%d\n", 2*maxl);

	return 0;
}
