#include<cstdio>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define mp make_pair
#define EPS 1e-9

struct Segment
{
	double x, y1, y2;
	bool left;
	int id;
	Segment(int id, double y1, double y2, double x = 0.0, bool left = 0): x(x), y1(y1), y2(y2), left(left), id(id) {}
	bool operator<(Segment other) const
	{
		if(fabs(x - other.x) < EPS)
		{
			if(fabs(y1 - other.y1) < EPS)
			{
				if(fabs(y2 - other.y2) < EPS)
					return (id < other.id);
				return (y2 < other.y2);
			}
			return (y1 < other.y1);
		}
		return (x < other.x);
	}
};

double lineSweep(vector<Segment> &seg)
{
	double area = 0.0, w, ymin, ymax;
	//keeps the vertical segments intersected with the sweep line
	set<Segment> height;
	height.clear();
	sort(seg.begin(), seg.end());
	
	height.insert(Segment(seg[0].id, seg[0].y1, seg[0].y2));
	for(int i=1; i<(int)seg.size(); ++i)
	{
		if(!height.empty())
		{
			w = seg[i].x - seg[i-1].x;
			ymin = (height.begin())->y1; 
			ymax = (height.begin())->y2;
			for(set<Segment>::iterator it0 = height.begin(); ; ++it0)
			{
				set<Segment>::iterator it1 = it0;
				++it1;
				if(it1 == height.end())
					break;
				if(it1->y1 > ymax)
				{
					area += w*(ymax - ymin);
					ymin = it1->y1;	
				}
				ymax = max(it1->y2, ymax);
			}
			area += w*(ymax - ymin);
		}
		
		if(seg[i].left)
			height.insert(Segment(seg[i].id, seg[i].y1, seg[i].y2));
		else
			height.erase(Segment(seg[i].id, seg[i].y1, seg[i].y2));
	}
	return area;
}

int main()
{
	double x, y, r;
	int n;
	//represent the vertical segments of the rectangles
	vector<Segment> seg;
	
	for(int data=1; scanf("%d", &n) && n; ++data)
	{
		seg.clear();
		for(int i=0; i<n; ++i)
		{
			scanf("%lf %lf %lf", &x, &y, &r);
			seg.push_back(Segment(i, y-r, y+r, x-r, 1));
			seg.push_back(Segment(i, y-r, y+r, x+r, 0));
		}
		printf("%d %.2lf\n", data, lineSweep(seg));
	}
	
	return 0;
}