#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

#define INF 1e9
#define EPS 1e-9

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
	bool operator<(Point other) const
	{
		return x < other.x;
	}
};

double dist(Point p1, Point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

//O(n*logn)
double lineSweep(vector<Point> &pnt)
{
	double d = INF;
	
	//keeps the points left of the sweep line that (dist(point, sweepline) <= actual optimal distance)
	set<Point> setx, sety; 
	
	setx.clear(); sety.clear();
	sort(pnt.begin(), pnt.end());
	for(int i=0; i<(int)pnt.size(); ++i)
	{
		//delete points that are left to the sweep line and that (dist(point, sweepline) > actual optimal distance)
		for(set<Point>::iterator it=setx.begin(); it!=setx.end(); ++it)
		{
			if(pnt[i].x - it->x > d)
			{
				setx.erase(it);
				sety.erase(Point(it->y, it->x));
			}
			else
				break;
		}
		
		//consider only the points in the strip that are on the interval [(anything, pnt[i]-d), (anything, pnt[i]+d)]
		//in the worst case this interval will contain 6 points
		for(set<Point>::iterator it = sety.lower_bound(Point(pnt[i].y - d, 0)); it != sety.upper_bound(Point(pnt[i].y + d, 0)); ++it)
			d = min(d, dist(pnt[i], Point(it->y, it->x)));
			
		sety.insert(Point(pnt[i].y, pnt[i].x));
		setx.insert(pnt[i]);
	}
	
	return d;
}

int main()
{
	int n;
	double x, y;
	vector<Point> pnt;
	
	while(scanf("%d", &n) && n)
	{
		pnt.clear();
		while(n--)
		{
			scanf("%lf %lf", &x, &y);
			pnt.push_back(Point(x, y));
		}
		double d = lineSweep(pnt);
		if(d >= 10000) 
			puts("INFINITY");
		else 
			printf("%.4lf\n", d);
	}
	
	return 0;
}