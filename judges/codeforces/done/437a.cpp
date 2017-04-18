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
#define MAX 105

int main()
{
	char s[4][MAX];
	
	for(int i=0; i<4; ++i) gets(s[i]);
	
	vector<int> sol;	
	for(int i=0; i<4; ++i)
	{
		int cntMin = 0, cntMax = 0;
		int l1 = strlen(s[i]) - 2;
		for(int j=0; j<4; ++j)
			if(i != j)
			{
				int l2 = strlen(s[j]) - 2;
				if(l2*2 <= l1) ++cntMax;
				else if(l1*2 <= l2) ++cntMin;
			}	
		if(cntMin == 3 || cntMax == 3) sol.pb(i);
	}
	
	if((int)sol.size() == 1) printf("%c\n", sol[0] + 'A');
	else puts("C");

	return 0;
}
