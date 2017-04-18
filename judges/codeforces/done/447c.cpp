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
#define MAX 100005

int v[MAX], dpLeft[MAX], dpRight[MAX];

int main()
{
	int n;

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	
	dpLeft[0] = dpRight[n-1] = 1;
	int sol = 1;
	
	for(int i=1; i<n; ++i)
	{
		if(v[i] > v[i-1]) dpLeft[i] = dpLeft[i-1] + 1;
		else dpLeft[i] = 1;
		
		sol = max(sol, dpLeft[i]);
		//printf("i= %d, left[i]= %d\n", i, dpLeft[i]);
	}
	for(int i=n-2; i>=0; --i)
	{
		if(v[i] < v[i+1]) dpRight[i] = dpRight[i+1] + 1;
		else dpRight[i] = 1;

		sol = max(sol, dpRight[i]);
		//printf("i= %d, right[i]= %d\n", i, dpRight[i]);
	}
	
	if(n > 1)
	{
		if(sol < n) sol++;
		sol = max(sol, dpRight[1] + 1);
		sol = max(sol, dpLeft[n-2] + 1);
	}

	for(int i=1; i<n-1; ++i)
	{
		if(v[i-1] >= v[i])
		{
			//printf("i= %d, v[i-1]= %d, v[i]= %d\n", i, v[i], v[i-1]);
			if(i + 1 < n && (v[i+1] - v[i-1]) <= 1) continue;
			sol = max(sol, dpRight[i] + dpLeft[i-1]);
		}
		else if(i+1 < n && v[i+1] <= v[i])
		{
			//printf("i= %d, v[i-1]= %d, v[i]= %d\n", i, v[i], v[i-1]);
			if((v[i+1] - v[i-1]) <= 1) continue;
			sol = max(sol, dpRight[i+1] + dpLeft[i]);
		}
	}
	
	printf("%d\n", sol);

	return 0;
}
