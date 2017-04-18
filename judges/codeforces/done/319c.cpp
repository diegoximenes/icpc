#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define MAX 100005

ll a[MAX], b[MAX];

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

//consider that ai > ai+1 (slope), the overall complexity of adding all lines is O(n)
void addLine(Line l)
{
	while(len >= 2 && irrelevant(convexHull[len-2], convexHull[len-1], l)) --len;
	convexHull[len++] = l;
}

/*
consider that queries are non-decreasing, the overall complexity of all queries is O(n).
if is not nod-decreasing use binary-search
*/
ll query(ll x) 
{
	ptr = min(ptr, len-1);
	while(ptr+1 < len && (convexHull[ptr+1].a * x + convexHull[ptr+1].b <= convexHull[ptr].a * x + convexHull[ptr].b))
		++ptr;
	return convexHull[ptr].a * x + convexHull[ptr].b;
}

int main()
{
	int n;

	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<n; ++i) cin >> b[i];
	
	len = ptr = 0;
	ll sol = 0;
	for(int i=0; i<n; ++i)
	{
		if(i != 0) sol = query(a[i]);
		addLine(Line(b[i], sol));
	}
	
	cout << sol << endl;

	return 0;
}
