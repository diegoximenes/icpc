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
#define INF 0x3f3f3f3f
#define EPS 1e-7
#define MAX 1005

char s[MAX];

int main()
{
	int t;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf(" %s ", s);
		int len = strlen(s);
		vector<int> num;
		for(int i=0; i<len; ++i) num.pb(s[i] - '0');

		int sol = 0;
		while(!num.empty())
		{
			vector<int> num2;
			if(num.back() % 2 != 0) ++sol;
			
			int aux = 0, first = 1;
			for(int i=0; i<(int)num.size(); ++i)
			{
				int nume;
				if(aux != 0) nume = aux*10 + num[i];
				else nume = num[i];

				if(nume < 2)
				{
					aux = nume;
					if(!first) num2.pb(0);
				}
				else
				{ 
					aux = nume%2;
					if(first && nume/2 == 0) continue;
					num2.pb(nume/2); first = 0;
				}

			}

			num = num2;
		}

		printf("%d\n", sol);
	}

	return 0;
}
