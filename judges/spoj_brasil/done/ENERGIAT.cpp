#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXP 5010
#define MAXF 22
#define INF (int) 1e9

int main()
{
	int f, p, etroca, ttroca, e[MAXP][MAXF], t[MAXP][MAXF], edpmin, pd[MAXP][MAXF];
	
	while(scanf("%d %d %d %d", &f, &p, &etroca, &ttroca))
	{
		if(!f && !p && !etroca && !ttroca)
			break;
		
		for(int i=0; i<p; ++i)
			for(int j=0; j<f; ++j)
				scanf("%d %d", &e[i][j], &t[i][j]);
		
		pd[0][0] = e[0][0]*t[0][0];
		for(int i=1; i<f; ++i)
			pd[0][i] = e[0][i]*t[0][i] + etroca*ttroca;
		
		for(int i=1; i<p; ++i)
			for(int j=0; j<f; ++j)
			{
				pd[i][j] = pd[i-1][j] + e[i][j]*t[i][j];
				for(int k=0; k<f; ++k)
					if(k != j)
						pd[i][j] = min(pd[i-1][k] + e[i][j]*t[i][j] + etroca*ttroca, pd[i][j]);
			}
		
		edpmin = INF;
		for(int i=0; i<f; ++i)
			edpmin = min(pd[p-1][i], edpmin);
		printf("%d\n", edpmin);
	}
	
	return 0;
}