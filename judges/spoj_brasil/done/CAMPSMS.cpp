#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define mp make_pair

#define MAX 300
double moveVel = 30, pressTime = 0.2, dp[11][11][MAX];

inline pair<double, double> idToPos(int id)
{
	pair<double, double> p;
	
	if(id==2 || id==3)
		p.second = 0.5;
	else if(id==4 || id==5 || id==6)
		p.second = 1.5;
	else if(id==7 || id==8 || id==9)
		p.second = 2.5;
	else
		p.second = 3.5;

	if(id==4 || id==7)
		p.first = 0.5;
	else if(id==2 || id==5 || id==8 || id==0)
		p.first = 1.5;
	else
		p.first = 2.5;
	
	return p;
}

inline int charToId(char c)
{
	if(c == ' ')
		return 0;
	if(c == '#')
		return 10;
	if(c>='a' && c<='c')
		return 2;
	if(c>='d' && c<='f')
		return 3;
	if(c>='g' && c<='i')
		return 4;
	if(c>='j' && c<='l')
		return 5;
	if(c>='m' && c<='o')
		return 6;
	if(c>='p' && c<='s')
		return 7;
	if(c>='t' && c<='v')
		return 8;
	return 9;
}

char first[10] = {0, 0, 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
inline int pressCount(char c)
{
	if(c==' ' || c=='#')
		return 1;
	return c-first[charToId(c)]+1;
}

inline double timeMove(pair<double, double> p1, pair<double, double> p2)
{
	return hypot(p1.first - p2.first, p1.second - p2.second)/moveVel;
}

double solve(int idl, int idr, char *s, int n)
{
	if(n<0)
		return 0;
	double &state = dp[idl][idr][n];
	if(state != -1)
		return state;
	
	int ids0 = charToId(s[0]);
	if(idl==ids0 || idr==ids0)
		return state = pressCount(s[0])*pressTime + solve(idl, idr, s+1, n-1);
	else
	{
		pair<double, double> pl = idToPos(idl), pr = idToPos(idr), ps0 = idToPos(ids0);
		double timel, timer, press = pressTime*pressCount(s[0]);
		timel = timeMove(pl, ps0) + press + solve(min(ids0, idr), max(ids0, idr), s+1, n-1);
		timer = timeMove(pr, ps0) + press + solve(min(ids0, idl), max(ids0, idl), s+1, n-1);
		return state = min(timel, timer);
	}
}

int main()
{
	char s[MAX], c;
	int l = 4, r = 6;

	while(1)
	{
		for(int i=0; i<11; ++i)
			for(int j=0; j<11; ++j)
				for(int k=0; k<MAX; ++k)
					dp[i][j][k] = -1;
		memset(s, '\0', sizeof(s));
		s[0] = getchar();
		if(s[0] == EOF)
			break;
		for(int i=1; ;++i)
		{
			c = getchar();
			if(c=='\n' || c==EOF)
				break;
			if(charToId(c) == charToId(s[i-1]))
			{
				s[i] = '#'; 
				s[++i] = c;
			}
			else
				s[i] = c;
		}
		printf("%.2lf\n", solve(l, r, s, strlen(s)-1));
	}
	return 0;
}

