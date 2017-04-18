#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define MAX (2*5005)
const int offset = 5000;

struct VerticalSegment
{
	public:
	int x, y1, y2;
	VerticalSegment(int x=0, int y1=0, int y2=0) : x(x), y1(y1), y2(y2) {} ;
};
struct HorizontalSegment
{
	public:
	int y, x1, x2;
	HorizontalSegment(int y=0, int x1=0, int x2=0) : y(y), x1(x1), x2(x2) {} ;
};

struct Cut
{
	public:
	bool isVertical;
	int x1, y1, x2, y2;
	Cut(bool isVertical, int x1, int y1, int x2, int y2) : isVertical(isVertical), x1(x1), y1(y1), x2(x2), y2(y2) {} ;
	bool operator<(Cut o) const
	{
		if(x1 != o.x1) return (x1 < o.x1);
		return (y1 < o.y1);
	}
};

struct Rect
{
	public:
	int x1, y1, x2, y2;
	Rect(int x1=0, int y1=0, int x2=0, int y2=0) : x1(x1), y1(y1), x2(x2), y2(y2) {};
};

int n;
vector< pair<int, int> > horizontal[MAX], vertical[MAX];
vector<HorizontalSegment> horizontalSeg;
vector<VerticalSegment> verticalSeg;

inline int id(int a) { return (a + offset); }

vector<Cut> merge(Cut cut0, vector<Cut> cut1, vector<Cut> cut2)
{
	vector<Cut> merged; merged.pb(cut0);
	
	int i = 0, j = 0;
	while(i < (int)cut1.size() || j < (int)cut2.size())
	{
		if(i == (int)cut1.size()) merged.pb(cut2[j++]);
		else if(j == (int)cut2.size()) merged.pb(cut1[i++]);
		else if(cut1[i] < cut2[j]) merged.pb(cut1[i++]);
		else merged.pb(cut2[j++]);
	}
	
	return merged;
}

vector<Cut> solve(int x1, int y1, int x2, int y2)
{
	//printf("x1= %d, y1= %d, x2= %d, y2= %d\n", x1, y1, x2, y2);
	
	vector<Cut> cut;

	for(int i=0; i<(int)verticalSeg.size(); ++i)
		if(verticalSeg[i].y1 <= y1 && verticalSeg[i].y2 >= y2 && verticalSeg[i].x > x1 && verticalSeg[i].x < x2)
			cut.pb(Cut(1, verticalSeg[i].x, y1, verticalSeg[i].x, y2));

	for(int i=0; i<(int)horizontalSeg.size(); ++i)
		if(horizontalSeg[i].x1 <= x1 && horizontalSeg[i].x2 >= x2 && horizontalSeg[i].y > y1 && horizontalSeg[i].y < y2)
			cut.pb(Cut(0, x1, horizontalSeg[i].y, x2, horizontalSeg[i].y));
	
	if(cut.empty()) return vector<Cut>();

	sort(cut.begin(), cut.end());

	vector<Cut> cut1, cut2;
	if(cut[0].isVertical)
	{
		cut1 = solve(x1, y1, cut[0].x1, y2);
		cut2 = solve(cut[0].x1, y1, x2, y2);
	}
	else
	{
		cut1 = solve(x1, y1, x2, cut[0].y1);
		cut2 = solve(x1, cut[0].y1, x2, y2);
	}
	
	return merge(cut[0], cut1, cut2);
}

int main()
{
	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<MAX; ++i) horizontal[i].clear(), vertical[i].clear();
		horizontalSeg.clear(); verticalSeg.clear();
		
		int minx = INF, maxx = -INF, miny = INF, maxy = -INF;
		int x1, x2, y1, y2;
		for(int i=0; i<n; ++i)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			
			minx = min(minx, x1); maxx = max(maxx, x2);
			miny = min(miny, y1); maxy = max(maxy, y2);
			
			horizontal[id(y1)].pb(mp(x1, x2));
			horizontal[id(y2)].pb(mp(x1, x2));

			vertical[id(x1)].pb(mp(y1, y2));
			vertical[id(x2)].pb(mp(y1, y2));
		}
		
		for(int i=0; i<MAX; ++i)
		{
			if(!horizontal[i].empty())
			{
				sort(horizontal[i].begin(), horizontal[i].end());
				int x1 = horizontal[i][0].first, x2 = horizontal[i][0].second;
				for(int j=1; j<(int)horizontal[i].size(); ++j)
				{
					if(horizontal[i][j].first <= x2) x2 = horizontal[i][j].second;
					else
					{ 
						horizontalSeg.pb(HorizontalSegment(i-offset, x1, x2));
						x1 = horizontal[i][j].first;
						x2 = horizontal[i][j].second;
					}
				}
				horizontalSeg.pb(HorizontalSegment(i-offset, x1, x2));
			}

			if(!vertical[i].empty())
			{
				sort(vertical[i].begin(), vertical[i].end());
				int y1 = vertical[i][0].first, y2 = vertical[i][0].second;
				for(int j=1; j<(int)vertical[i].size(); ++j)
				{
					if(vertical[i][j].first <= y2) y2 = vertical[i][j].second;
					else
					{ 
						verticalSeg.pb(VerticalSegment(i-offset, y1, y2));
						y1 = vertical[i][j].first;
						y2 = vertical[i][j].second;
					}
				}
				verticalSeg.pb(VerticalSegment(i-offset, y1, y2));
			}
		}
		
		vector<Cut> cut = solve(minx, miny, maxx, maxy);
		for(int i=0; i<(int)cut.size(); ++i) printf("%d %d %d %d\n", cut[i].x1, cut[i].y1, cut[i].x2, cut[i].y2);
		puts("");	

		/*puts("horizontalSeg= ");
		for(int i=0; i<(int)horizontalSeg.size(); ++i) printf("i= %d, y= %d, x1= %d, x2= %d\n", i, horizontalSeg[i].y, horizontalSeg[i].x1, horizontalSeg[i].x2);
		puts("");
		puts("verticalSeg= ");
		for(int i=0; i<(int)verticalSeg.size(); ++i) printf("i= %d, x= %d, y1= %d, y2= %d\n", i, verticalSeg[i].x, verticalSeg[i].y1, verticalSeg[i].y2);
		puts("");*/
	}

	return 0;
}
