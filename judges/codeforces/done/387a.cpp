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

inline int tomin(int h, int m)
{
	return h*60 + m;
}

pair<int, int> tohour(int m)
{
	return mp(m/60, m%60); 
}

int main()
{
	int h1, m1, h2, m2, t1, t2;

	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	t1 = tomin(h1, m1);
	t2 = tomin(h2, m2);

	int t = t1 - t2;
	if(t < 0) t += 24*60;
	pair<int, int> p = tohour(t);

	if(p.first < 10 && p.second < 10) printf("0"), printf("%d", p.first), printf(":0"), printf("%d\n", p.second);
	else if(p.first < 10) printf("0"), printf("%d:%d\n", p.first, p.second);
	else if(p.second < 10) printf("%d:", p.first), printf("0"), printf("%d\n", p.second);
	else printf("%d:%d\n", p.first, p.second);

	return 0;
}
