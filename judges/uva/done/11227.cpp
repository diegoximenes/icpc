#include<cstdio>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

#define mp make_pair
#define EPS 1e-8

struct Line { double a, b, c; };

void pointsToLine(pair<double, double> p1, pair<double, double> p2, Line &l)
{
	if(p1.first == p2.first)
	{
		l.a = 1.0; l.b = 0.0; l.c = -p1.first;
	}
	else
	{
		l.a = -(p1.second - p2.second)/(p1.first - p2.first);
		l.b = 1.0;
		l.c = -(l.a * p1.first) - (l.b * p1.second);
	}
}

int main()
{
	int t, n, count, gnu, countaux;
	double x, y;
	Line line;
	vector<Line> l;
	set< pair<double, double> > p; 
	set< pair<double, double> >::iterator it, it2;
	
	scanf("%d", &t);
	for(int k=1; k<=t; ++k)
	{
		p.clear();
		gnu = 0;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%lf %lf", &x, &y);
			if(p.find(mp(x, y)) == p.end())
			{
				p.insert(mp(x, y));
				++gnu;
			}
		}

		count = 0;
		for(it=p.begin(); it!=p.end(); ++it)
		{
			l.clear();
			for(it2=p.begin(); it2!=p.end(); ++it2)
				if(it != it2)
				{
					pointsToLine(*it, *it2, line);
					l.push_back(line);
					
				}

			for(int i=0; i<(int)l.size(); ++i)
			{
				countaux = 2;
				for(int j=0; j<(int)l.size(); ++j)
					if((j != i) && (fabs(l[i].a - l[j].a) < EPS) && (fabs(l[i].b - l[j].b) < EPS) && (fabs(l[i].c - l[j].c) < EPS))
						++countaux;
		
				count = max(count, countaux);
			}
		}
		
		if(gnu == 1)
			printf("Data set #%d contains a single gnu\n.", k);
		else
			printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n", k, gnu, count);
		
	}
	
	return 0;
}