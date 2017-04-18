#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

#define EPS 1e-9
#define INF 1e9

typedef struct Line
{
	double a, b, c;
}Line;

typedef struct Point
{
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y) {}
}Point;

typedef struct Segment
{
	Point p1, p2;
	Segment(Point p1, Point p2): p1(p1), p2(p2) {}
}Segment;

Line pointsToLine(Point p1, Point p2)
{
	Line l;
	if(p1.x == p2.x)
	{
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}
	else
	{
		l.a = (p1.y - p2.y)/(p2.x - p1.x);
		l.b = 1.0;
		l.c = (p1.x*p2.y - p2.x*p1.y)/(p2.x - p1.x);
	}
	return l;
}

Line paralellLine(Line s, Point p)
{
	Line r;
	if(fabs(s.a) < EPS)
	{
		r.a = 1; r.b = 0; r.c = -p.x;
	}
	else
	{
		r.a = -s.b/s.a;
		r.b = 1;
		r.c = s.b/s.a*p.x - p.y;
	}
	return r;
}

Point intersect(Line s, Line r)
{
	Point p;
	if(fabs(r.b) < EPS)
	{
		p.x = -r.c/r.a;
		p.y = (-s.c -s.a*p.x)/s.b;
	}
	else
	{
		p.x = (s.b*r.c/r.b - s.c)/(s.a - s.b*r.a/r.b);
		p.y = -r.a/r.b*p.x - r.c/r.b;
	}
	return p;
}

bool pointInSegment(Segment s, Point p)
{
	if(((p.x <= max(s.p1.x, s.p2.x)) && (p.x >= min(s.p1.x, s.p2.x))) && ((p.y <= max(s.p1.y, s.p2.y)) && (p.y >= min(s.p1.y, s.p2.y))))
		return 1;
	return 0;
}

double pointsDistance(Point p1, Point p2)
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main()
{
	int n;
	double xm, ym, x0, x1, y0, y1;
	Line l;
	vector<Line> lns;
	vector<Segment> segs;
	
	while(scanf("%lf %lf %d", &xm, &ym, &n) == 3)
	{
		Point m(xm, ym);
		lns.clear(); segs.clear();
		scanf("%lf %lf", &x0, &y0);
		while(n--)
		{
			scanf("%lf %lf", &x1, &y1);
			lns.push_back(pointsToLine(Point(x0, y0), Point(x1, y1)));
			segs.push_back(Segment(Point(x0, y0), Point(x1, y1)));
			
			x0 = x1; y0 = y1;
		}
		
		Point pint;
		double dist = INF;
		for(int i=0; i<(int)lns.size(); ++i)
		{
			l = paralellLine(lns[i], m);
			Point p = intersect(lns[i], l);
			if(pointInSegment(segs[i], p))
			{
				if(dist > pointsDistance(m, p))
				{
					dist = pointsDistance(m, p);
					pint.x = p.x; pint.y = p.y;
				}
			}
			else
			{
				if(dist > pointsDistance(m, segs[i].p1))
				{
					dist = pointsDistance(m, segs[i].p1);
					pint.x = segs[i].p1.x; pint.y = segs[i].p1.y;
				}
				if(dist > pointsDistance(m, segs[i].p2))
				{
					dist = pointsDistance(m, segs[i].p2);
					pint.x = segs[i].p2.x; pint.y = segs[i].p2.y;
				}
			}
		}
		
		printf("%.4lf\n%.4lf\n", pint.x, pint.y);
	}
	
	return 0;
}
