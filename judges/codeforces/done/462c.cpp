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
#define EPS 1e-9
#define MAX 300005

ll v[MAX], cumRight[MAX];

int main()
{
	int n;
	ll sum = 0;

	scanf("%d", &n);
	for(int i=0; i<n; ++i) cin >> v[i], sum += v[i];
	sort(v, v+n);
	
	cumRight[n-1] = v[n-1];
	for(int i=n-2; i>=0; --i) cumRight[i] = cumRight[i+1] + v[i];
	
	ll sol = 0;
	for(int i=0; i<n-1; ++i) sol += cumRight[i];
	
	sol += sum;

	cout << sol << endl;

	return 0;
}
