#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

#define EPS 1e-9
#define PI acos(-1)
#define INF 1e9

struct Point
{
	double x, y;
	Point(double x=0, double y=0): x(x), y(y) {}
};

struct Line
{
	double a, b, c;
};

Line pointsToLine(Point p1, Point p2)
{
	Line l;
	if(fabs(p1.x - p2.x) < EPS)
	{
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}
	else
	{
		l.a = (p1.y - p2.y)/(p2.x - p1.x);
		l.b = 1.0;
		l.c = (p2.x*p1.y - p1.x*p2.y)/(p2.x - p1.x);
	}
	return l;
}

Line parallelLine(Line r, Point p1, Point p2)
{
	Line s;
	if(fabs(r.a) < EPS)
	{
		s.a = 1.0; s.b = 0.0; 
	}
	else
	{
		s.a = -r.b/r.a; s.b = 1.0;
	}
	s.c = -s.a*(p1.x + p2.x)/2.0 - s.b*(p1.y + p2.y)/2.0;
	return s;
}

Point intersect(Line r, Line s)
{
	Point p;
	if(fabs(r.b) < EPS)
	{
		p.x = -r.c/r.a;
		p.y = (-s.a*p.x - s.c)/s.b;
	}
	else
	{
		p.x = (s.b*r.c/r.b - s.c)/(s.a - s.b*r.a/r.b);
		p.y = -r.a/r.b*p.x - r.c/r.b;
	}
	return p;
}

double dist(Point p1, Point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main()
{
	int n;
	double radius, teta, delta, x1, x2, x3, y1, y2, y3;
	Line r, s, t, u;
	vector<Point> pnt;
	
	for(int pol=1; scanf("%d", &n) && n; ++pol)
	{
		pnt.clear();
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
		Point a(x1, y1), b(x2, y2), c(x3, y3), center;
		
		r = pointsToLine(a, b);
		s = pointsToLine(a, c);
		t = parallelLine(r, a, b);
		u = parallelLine(s, a, c);
		center = intersect(t, u);
		radius = dist(center, a);
		
		//deslocate center to (0,0)
		a.x -= center.x;
		a.y -= center.y;
		
		teta = acos(a.x/radius);
		delta = 2*PI/n;
		pnt.push_back(a);
		while(--n)
		{
			teta = teta + delta;
			pnt.push_back(Point(radius*cos(teta), radius*sin(teta)));
		}
		
		double xmin = INF, ymin = INF, xmax = -INF, ymax = -INF;
		for(int i=0; i<(int)pnt.size(); ++i)
		{
			xmin = min(xmin, pnt[i].x);
			ymin = min(ymin, pnt[i].y);
			xmax = max(xmax, pnt[i].x);
			ymax = max(ymax, pnt[i].y);
		}
		
		printf("Polygon %d: %.3lf\n", pol, (xmax-xmin)*(ymax-ymin));
	}
	
	return 0;
}