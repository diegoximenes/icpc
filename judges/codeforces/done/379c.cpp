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

int main()
{
	int n, sol, a;
	set< int > tree, mark;
	set< int >::iterator it, it2;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &a);
		//printf("a= %d\n", a);
		if(mark.find(a) != mark.end())
		{
			it = tree.upper_bound(a-1);
			if(it == tree.end()) 
			{
				//puts("oi1");
				tree.insert(a+1);
				sol = a;
			}
			else
			{ 
				//puts("oi2");
				sol = *it;
				tree.erase(it);
				if(mark.find(sol+1) == mark.end()) tree.insert(sol + 1);
			}
		}
		else
		{
			//puts("oi3");
			tree.erase(a);
			sol = a;
		
			if(mark.find(a+1) == mark.end()) tree.insert(a+1);
		}
		
		mark.insert(sol);
		if(i == 0) printf("%d", sol);
		else printf(" %d", sol);
	}
	puts("");
	
	return 0;
}
