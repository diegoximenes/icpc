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
#define MAX 1000010 

int main()
{
	int k, p, x[MAX], add[MAX];
	set< vector<int> > tree;
	
	scanf("%d %d", &p, &k);
	for(x[0]=1; x[0]<=9; ++x[0])
	{
		x[1] = (k*x[0])%10; 
		add[2] = (k*x[0])/10;
		for(int i=2; i<p; ++i)
		{
			x[i] = (k*x[i-1] + add[i])%10;
			add[i+1] = (k*x[i-1] + add[i])/10;
		}
		if(x[0] == k*x[p-1] + (k*x[p-2])/10 && x[p-1] != 0)
		{
			vector<int> v;
			v.pb(x[p-1]);
			for(int i=p-2; i>=0; --i) v.pb(x[i]);
			tree.insert(v);
		}
	}
	
	if(!tree.empty())
	{
		vector<int> v = *tree.begin();
		for(int i=0; i<p; ++i) printf("%d", v[i]);
		puts("");
	}
	else puts("Impossible");

	return 0;
}
