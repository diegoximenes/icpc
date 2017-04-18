#include<cstdio>
using namespace std;

int main()
{
	double v, sol;
	int n, m, g[100], group;
	
	int count = 0;
	for(int i=1; i<100; i+=4)
		g[i] = g[i+1] = g[i+2] = g[i+3] = count++;
	g[0] = count;

	while(scanf("%lf %d %d", &v, &n, &m) && v != 0.0)
	{
		bool d1 = m%10 == n%10, d2 = m/10%10 == n/10%10, d3 = m/100%10 == n/100%10, d4 = m/1000%10 == n/1000%10;
		
		if(d1 && d2 && d3 && d4) sol = v*3000;
		else if(d1 && d2 && d3) sol = v*500;
		else if(d1 && d2) sol = v*50;
		else if(g[m%100] == g[n%100]) sol = v*16;
		else sol = 0;

		printf("%.2lf\n", sol);
	}

	return 0;
}
