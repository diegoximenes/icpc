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

int main()
{
	int sum, limit, cnt[35], cntSol[35];

	scanf("%d %d", &sum, &limit);
	
	memset(cnt, 0, sizeof(cnt));
	memset(cntSol, 0, sizeof(cntSol));

	for(int i=1; i<=limit; ++i)
		for(int j=0; j<32; ++j)
			if((1 << j) & i)
			{
				cnt[j]++;
				break;
			}
	
	for(int i=31; i>=0; --i)
		if(sum & (1 << i))
		{
			int aux = 0;

			for(int j=i; (aux != (1 << i)) && j>=0; --j)
				while(cnt[j])
				{
					aux += (1 << j);
					cntSol[j]++; --cnt[j];
					if(aux == (1 << i)) break;
				}
			sum -= aux;
		}

	if(sum) puts("-1");
	else
	{
		vector<int> sol;
		for(int i=1; i<=limit; ++i)
			for(int j=0; j<32; ++j)
				if((1 << j) & i)
				{
					if(cntSol[j]) --cntSol[j], sol.pb(i);
					break;
				}
		
		printf("%d\n%d", (int)sol.size(), sol[0]);
		for(int i=1; i<(int)sol.size(); ++i) printf(" %d", sol[i]);
		puts("");
	}

	return 0;
}
