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
#define MAX 200010

bool can1[MAX], can2[MAX];
pair< pair<int, int>, int > v[MAX];

int main()
{
	int n;

	scanf("%d", &n);
	for(int i=0, j=0; i<n; i++, j+=2)
	{
		scanf("%d %d", &v[j].first.first, &v[j+1].first.first);
		v[j].first.second = 1; v[j+1].first.second = 2;
		v[j].second = v[j+1].second = i;
	}

	sort(v, v+2*n);
	for(int i=0; i<n; ++i)
	{
		if(v[i].first.second == 1) can1[v[i].second] = 1;
		else can2[v[i].second] = 1;
	}
	int upper;
	if(n%2 == 0) upper = n;
	else upper = n-1;
	for(int i=0; 2*i<upper; ++i) can1[i] = can2[i] = 1;
	
	for(int i=0; i<n; ++i) printf("%d", can1[i]);
	puts("");
	for(int i=0; i<n; ++i) printf("%d", can2[i]);
	puts("");

	return 0;
}
