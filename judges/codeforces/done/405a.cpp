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
#define MAX 105

int main()
{
	int n, a[MAX];

	scanf("%d", &n);	
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);

	sort(a, a+n);
	printf("%d", a[0]);
	for(int i=1; i<n; ++i) printf(" %d", a[i]);
	puts("");

	return 0;
}
