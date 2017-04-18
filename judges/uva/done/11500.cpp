#include<cstdio>
#include<map>
using namespace std;

#define mp make_pair
#define MAX 30

map< pair<int, int>, int> dic;
map< int, pair<int, int> > dic2;

void state(int e1, int e2, int d)
{
	if((e1 <= 0) || (e2 <= 0))
		return;
	if(dic.find(mp(e1, e2)) == dic.end())
	{
		int s = dic.size();
		dic[mp(e1, e2)] = s;
		dic2[s] = mp(e1, e2);
		state(e1 - d, e2 + d, d);
		state(e1 + d, e2 - d, d);
	}
}

//c = a*b, a,b,c: nxn -> nxn
void mulMatrix(double a[MAX][MAX], double b[MAX][MAX], double c[MAX][MAX], int n)
{
	int k;
	double a2[MAX][MAX], b2[MAX][MAX];
	for(int i = 0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			a2[i][j] = a[i][j];
			b2[i][j] = b[i][j];
		}
	for(int i = 0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(c[i][j] = k = 0; k<n; ++k)
				c[i][j] += a2[i][k]*b2[k][j];
}

//r = base**e, base: nxn
void powMatrix(double base[MAX][MAX], int e, double r[MAX][MAX], int n)
{
	for(int i = 0; i<n; ++i)
		for(int j=0; j<n; ++j)
			r[i][j] = (i == j);
	while(e)
	{		
		if(e & 1)
			mulMatrix(r, base, r, n);
		mulMatrix(base, base, base, n);
			
		e >>= 1;
	}
}

void initMatrix(double m[MAX][MAX], int n)
{
	for(int i = 0; i<n; ++i)
		for(int j=0; j<n; ++j)
			m[i][j] = 0.0;
}

int main()
{
	int e1, e2, d, w1, w2;
	double a, p[MAX][MAX];

	while(scanf("%d %d %lf %d", &e1, &e2, &a, &d) && e1)
	{
		dic.clear(); dic2.clear();
		state(e1, e2, d);
		
		w1 = dic.size();
		w2 = w1 + 1;
		initMatrix(p, dic.size()+2);

		for(int i=0; i<(int)dic.size(); ++i)
		{
			pair<int, int> s = dic2[i];

			if(s.second - d <= 0)
				p[i][w1] = a/6.0;
			else
			{
				int v2 = dic[mp(s.first + d, s.second - d)];
				p[i][v2] = a/6.0;
			}
			if(s.first - d <= 0)
				p[i][w2] = (6.0 - a)/6.0;
			else
			{
				int v2 = dic[mp(s.first - d, s.second + d)];
				p[i][v2] = (6.0 - a)/6.0;
			}
		}
		p[w1][w1] = p[w2][w2] = 1.0;

		int inf = 610;
		double pn[MAX][MAX];
		powMatrix(p, inf, pn, dic.size()+2);
		printf("%.1lf\n", pn[0][w1]*100);
	}
	
	return 0;
}
