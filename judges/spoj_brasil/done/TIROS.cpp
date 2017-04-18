#include<cstdio>
#include<map>
#include<cmath>
using namespace std;

#define MAX 1005
#define EPS 1e-9

struct point
{
	double x, y;
	point(double x=0, double y=0) : x(x), y(y) {}
	
	bool operator<(point other) const
	{
		if(fabs(x - other.x) < EPS)
			return y < other.y;
		return x < other.x;
	}
	point operator-(point other)
	{
		point p;
		p.x = x - other.x;
		p.y = y - other.y;
		return p;
	}
	void normalize()
	{
		double mod = sqrt(x*x + y*y);
		x /= mod; y /= mod;

		if((x <= 0 && y <= 0) || (x <= 0 && y >= 0))
		{
			x *= -1; y *= -1;
		}
	}
};

int main()
{
	int tc, n, count, maxcount;
	point pnt[MAX];
	map<point, int> dic;

	scanf("%d", &tc);
	while(tc--)
	{
		maxcount = 0;
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			scanf("%lf %lf", &pnt[i].x, &pnt[i].y);

		for(int i=0; i<n; ++i)
		{
			count = 0; dic.clear();
			for(int j=0; j<n; ++j)
				if(i != j)
				{
					point v = pnt[j]-pnt[i];
					v.normalize();
					if(dic.find(v) == dic.end()) dic[v] = 1;
					else ++dic[v];
					count = max(count, dic[v]);
					//printf("i= %d, j= %d, v=(%lf, %lf)\n", i, j, v.x, v.y);
				}
			maxcount = max(maxcount, count);
		}
		printf("%d\n", maxcount + 1);
	}

	return 0;
}

