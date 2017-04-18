#include<cstdio>
using namespace std;

bool wina, winb;
char g[6][6];

void check(int i, int j, int di, int dj)
{
	int cnta = 0, cntb = 0;
	
	if(g[i][j] == 'A') cnta++;
	else cntb++;

	while(1)
	{
		i += di; j += dj;
		if(i >= 5 || j >= 5 || i<0 || j<0) return;

		if(g[i][j] == 'A')
		{
			if(g[i-di][j-dj] == 'B') cnta = 1;
			else cnta++;
		}
		else
		{
			if(g[i-di][j-dj] == 'A') cntb = 1;
			else cntb++;
		}

		if(cnta >= 3) wina = 1;
		if(cntb >= 3) winb = 1;
	}
}

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		wina = 0; winb = 0;

		for(int i=0; i<5; ++i) scanf(" %s ", g[i]);
		
		for(int i=0; i<5; ++i)
			for(int j=0; j<5; ++j)
				check(i, j, 0, 1), check(i, j, 1, 0), check(i, j, 1, 1), check(i, j, -1, 1);

		if((wina && winb) || (!wina && !winb)) puts("draw");
		else if(wina) puts("A wins");
		else puts("B wins");
	}

	return 0;
}
