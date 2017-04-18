#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

#define MAX 2010
#define INF 1e9
#define EPS 1e-9

#define mp make_pair

struct Point
{
	double x, y, z;
	Point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
	bool operator<(Point other) const
	{
		if(fabs(x - other.x) < EPS)
		{
			if(fabs(y - other.y) < EPS)
				return (z < other.z);
			return (y < other.y);
		}
		return (x < other.x);
	}
};

Point toVector(Point p1, Point p2)
{
	Point p;
	double mod = 0;
	
	p.x = p2.x - p1.x;
	p.y = p2.y - p1.y;
	p.z = p2.z - p1.z;
	
	mod = sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
	p.x /= mod; p.y /= mod; p.z /= mod;
	
	return p;
}

int main()
{
	int n;
	Point p[MAX];
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
	sort(p, p+n);
	
	int maxPoints = -INF;
	for(int i=0; i<n; ++i)
	{
		map<Point, int> dic;
		map<Point, int>::iterator it;
		dic.clear();
		for(int j=i+1; j<n; ++j)
		{
			Point v = toVector(p[i], p[j]);

			it = dic.find(v);
			if(it == dic.end())
				dic[v] = 2;
			else
				++it->second;
		}
		
		for(it=dic.begin(); it!=dic.end(); ++it)
			maxPoints = max(maxPoints, it->second);
	}

	
	if(maxPoints <= 0)
		puts("1");
	else
		printf("%d\n", maxPoints);
	
	return 0;
}