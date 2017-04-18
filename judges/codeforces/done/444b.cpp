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
#define MAX 55

int size[MAX], dset[MAX], n;

void init()
{
	for(int i=0; i<n; ++i) dset[i] = i, size[i] = 1;
}

int findSet(int i) { return ((dset[i] == i) ? i : (dset[i] = findSet(dset[i]))); } 

bool sameSet(int i, int j) { return (findSet(i) == findSet(j)); }

void unionSet(int i, int j)
{
	if(sameSet(i, j)) return;
	size[findSet(j)] += size[findSet(i)];
	dset[findSet(i)] = findSet(j);
}

int main()
{
	int m, u, v;
	
	scanf("%d %d", &n, &m);
	init();
	while(m--)
	{
		scanf("%d %d", &u, &v);
		unionSet(u-1, v-1);
	}
	
	ll sol = 0;
	set<int> mark;
	for(int i=0; i<n; ++i)
		if(mark.find(findSet(i)) == mark.end())
		{	
			mark.insert(findSet(i));
			ll aux = (1LL << (size[findSet(i)]-1));
			if(sol == 0) sol = aux;
			else sol *= aux;

		}
	cout << sol << endl;

	return 0;
}
