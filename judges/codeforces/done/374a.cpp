#include<cstdio>
#include<algorithm>
using namespace std;

#define INF (int) 1e9

int main()
{
	int n, m, xi, yi, a, b, m1, m2, m3, m4, mmin = INF;

	scanf("%d %d %d %d %d %d", &n, &m, &xi, &yi, &a, &b);
	const int end[4][2] = {{1, m}, {n, 1}, {n, m}, {1, 1}};
	
	for(int i=0; i<4; ++i)
	{
		if((2*a*(end[i][1]-yi) - 2*b*(end[i][0]-xi))%(2*a*2*b) != 0 || (2*a*(end[i][1]-yi) + 2*b*(end[i][0]-xi))%(2*a*2*b) != 0) continue;
		
		int v1 = (2*a*(end[i][1]-yi) - 2*b*(end[i][0]-xi))/(2*a*2*b), v2 = (2*a*(end[i][1]-yi) + 2*b*(end[i][0]-xi))/(2*a*2*b);
		
		if(v1 >= 0) m2 = 0, m3 = v1;
		else m2 = -v1, m3 = 0;
		
		if(v2 >= 0) m1 = 0, m4 = v2;
		else m1 = -v2, m4 = 0;
		
		if((m2 + m4 > m1 + m3) && ((m2 + m4 - m1 - m3)*a + xi > n)) continue;
		else if((m2 + m4 < m1 + m3) && ((m1 + m3 - m2 - m4)*(-a) + xi <= 0)) continue;		
		else if(((m2 || m4) && (xi + a > n)) && ((m1 || m3) && (xi - a <= 0))) continue;
		if((m3 + m4 > m1 + m2) && ((m3 + m4 - m1 - m2)*b + yi > m)) continue;		
		else if((m3 + m4 < m1 + m2) && ((m1 + m2 - m3 - m4)*(-b) + yi <= 0)) continue;		
		else if(((m3 || m4) && (yi + b > m)) && ((m1 || m2) && (yi - b <= 0))) continue;

		if((xi -a*(m1+m3) + a*(m2+m4) == end[i][0]) && (yi -b*(m1+m2) + b*(m3+m4) == end[i][1]))
			mmin = min(mmin, m1+m2+m3+m4);
	}
	
	if(mmin == INF) puts("Poor Inna and pony!");
	else printf("%d\n", mmin);

	return 0;
}
