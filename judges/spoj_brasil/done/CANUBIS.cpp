#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;

int sol;

struct Point
{
	int x, y, z;
	
	Point(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
	
	void operator=(Point other)
	{
		x = other.x; y = other.y; z = other.z;
	}
	Point operator-(Point other)
	{
		Point p;
		p.x = x - other.x;
		p.y = y - other.y;
		p.z = z - other.z;
		return p;
	}
	Point operator*(Point other)
	{
		Point p;
		p.x = y*other.z - z*other.y;
		p.y = z*other.x - x*other.z;
		p.z = x*other.y - y*other.x;
		return p;
	}

};

Point pnt[55];

inline bool isZero(Point v)
{
	if(v.x == 0 && v.y == 0 && v.z == 0) return 1;
	return 0;
}

void generate(bool *mark, int height, int n, int count)
{
	if(count == 3)
	{
		Point p[3], v1, v2, vPlane;

		int j = 0;
		for(int i=0; i<height; ++i)
			if(mark[i])
			{
				p[j] = pnt[i];
				++j;
			}
		
		v1 = p[1] - p[0];
		v2 = p[2] - p[0];
		if(isZero(v1) || isZero(v2)) return;
		vPlane = v2*v1;
		
		int count = 3;
		for(int i=0; i<n; ++i)
			if(!mark[i])
			{
				v1 = pnt[i] - p[0];

				if(isZero(vPlane))
				{
					if(isZero(v2*v1))
						++count;
				}
				else
				{
					if((v1.x*vPlane.x + v1.y*vPlane.y + v1.z*vPlane.z) == 0 || isZero(v1))
						++count;
				}
			}
		
		sol = max(sol, count);
	}
	else if(count > 3 || height == n) return;
	else
	{
		mark[height] = 1;
		generate(mark, height + 1, n, count + 1);
		mark[height] = 0;
		generate(mark, height + 1, n, count);
	}
}

int main()
{
	bool mark[55];
	int tc, n;
	
	scanf("%d", &tc);
	while(tc--)
	{
		memset(mark, 0, sizeof(mark));

		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			scanf("%d %d %d", &pnt[i].x, &pnt[i].y, &pnt[i].z);
		
		if(n <= 3) printf("%d\n", n);
		else
		{
			sol = 0; 
			generate(mark, 0, n, 0);
			printf("%d\n", sol);
		}
	}
	return 0;
}
