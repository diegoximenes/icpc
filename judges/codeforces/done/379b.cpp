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

#define ll long long
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 310
#define LEFT 1
#define RIGHT 0

int v[MAX];

int main()
{
	int n, acum = 0, pos = 0, cameFrom = RIGHT;
	set<int> tree;
	set<int>::reverse_iterator rit;
	set<int>::iterator it;

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]), acum += v[i], tree.insert(i);
	while(1)
	{
		if(v[pos]) putchar('P'), --v[pos], --acum;
		else tree.erase(pos);
		if(acum == 0) break;

		if(cameFrom == RIGHT && pos != 0)
		{
			it = tree.begin();
			if(*it < pos) pos--, cameFrom = RIGHT, putchar('L');
			else pos++, cameFrom = LEFT, putchar('R');
		}
		else if(cameFrom == RIGHT && pos == 0) pos++, cameFrom = LEFT, putchar('R');
		else if(cameFrom == LEFT && pos != n-1)
		{
			rit = tree.rbegin();
			if(*rit > pos) pos++, cameFrom = LEFT, putchar('R');
			else pos--, cameFrom = RIGHT, putchar('L');
		}
		else if(cameFrom == LEFT && pos == n-1) pos--, cameFrom = RIGHT, putchar('L');
	}
	puts("");

	return 0;
}
