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
#define MAX 1005

int main()
{
	char s[MAX];
	set<char> tree;
	
	gets(s);
	int n = strlen(s);
	for(int i=0; i<n; ++i)
		if(isalpha(s[i]))
			tree.insert(s[i]);

	printf("%d\n", (int)tree.size());

	return 0;
}
