#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define MAX 1000000

ll x[MAX], cum[MAX], dp[MAX];

struct Line
{
	ll a, b;
	Line(ll _a=0, ll _b=0) : a(_a), b(_b) {}
};

Line convexHull[MAX];
int ptr, len;

bool irrelevant(Line l1, Line l2, Line l3)
{
	double left = (double)(l3.b - l1.b)/(double)(l1.a - l3.a);
	double right = (double)(l2.b - l1.b)/(double)(l1.a - l2.a);
	return (left < right);
}

void addLine(Line l)
{
	while(len >= 2 && irrelevant(convexHull[len-2], convexHull[len-1], l)) --len;
	convexHull[len++] = l;
}

/*
for min query change comparison to <=
for max query change comparison to >=
*/
ll query(ll x) 
{
	ptr = min(ptr, len-1);
	while(ptr+1 < len && (convexHull[ptr+1].a * x + convexHull[ptr+1].b >= convexHull[ptr].a * x + convexHull[ptr].b))
		++ptr;
	return convexHull[ptr].a * x + convexHull[ptr].b;
}

int main()
{
	int t, n;
	ll a, b, c;
	
	scanf("%d", &t);	
	while(t--)
	{
		ptr = len = 0;

		scanf("%d %lld %lld %lld\n", &n, &a, &b, &c);
		cum[0] = 0;
		for(int i=1; i<=n; ++i) scanf("%lld", &x[i]), cum[i] = cum[i-1] + x[i];
		
		dp[1] = a*x[1]*x[1] + b*x[1] + c;
		addLine(Line(-2*a*cum[1], dp[1] + a*cum[1]*cum[1] - b*cum[1]));
		for(int i=2; i<=n; ++i)
		{
			dp[i] = query(cum[i]) + a*cum[i]*cum[i] + b*cum[i] + c;
			dp[i] = max(dp[i], a*cum[i]*cum[i] + b*cum[i] + c);
			addLine(Line(-2*a*cum[i], a*cum[i]*cum[i] - b*cum[i] + dp[i]));
		}

		printf("%lld\n", dp[n]);
	}

	return 0;
}
