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
#define EPS 1e-9

inline bool isInteger(double d)
{
	if(fabs(d - round(d)) < EPS) return 1;
	return 0;
}

int main()
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	
	bool solved = 0;
	for(int x1=1; x1<a; ++x1)
	{
		double y = sqrt(a*a - x1*x1);
		if(isInteger(y))
		{
			int y1 = round(y);
			double m2 = -(double)x1/(double)y1;

			double x2 = (double)b/sqrt(1 + m2*m2), y2 = m2*x2;
			if(isInteger(x2) && isInteger(y2))
			{
				int ix2 = round(x2), iy2 = round(y2);
				if(ix2 == x1 || iy2 == y1) ix2 *= -1, iy2 *= -1;
				if(ix2 == x1 || iy2 == y1) continue;
				
				solved = 1;
				printf("YES\n0 0\n%d %d\n%d %d\n", x1, y1, ix2, iy2);
				break;
			}
		}
	}

	if(!solved) puts("NO");

	return 0;
}
