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
#define EPS 1e-7
#define MAX 100005

int v[MAX];

int main()
{
	int t, s;
	double c, r;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %lf %lf", &s, &c, &r);

		double t = 0;
		for(int i=0; i<s; ++i) scanf("%d", &v[i]);
		sort(v, v+s);

		for(int i=0; i<s; ++i)
		{
			int dv = 0;
			if(c > 0) dv = r;
			t += 1.0/(double)(v[i] + dv);
			--c;
		}

		printf("%.2lf\n", t);
	}
		

	return 0;
}
