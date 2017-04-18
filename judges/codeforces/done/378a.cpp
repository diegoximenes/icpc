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
	int a, b, win = 0, lost = 0;

	scanf("%d %d", &a, &b);
	for(int i=1; i<=6; ++i)
	{
		if(abs(a-i) < abs(b-i)) ++win;
		else if(abs(b-i) < abs(a-i)) ++lost;
	}
	printf("%d %d %d\n", win, 6-win-lost, lost);

	return 0;
}
