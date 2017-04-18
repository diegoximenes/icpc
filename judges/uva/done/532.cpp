#include<cstdio>
#include<queue>
using namespace std;

#define MAX 30

int l, r, c;

typedef struct
{
	int i, j, k;
}Cel;

bool in(int i, int j, int k)
{
	if((i>=0) && (i<l) && (j>=0) && (j<r) && (k>=0) && (k<c))
		return 1;
	return 0;
}

int main()
{
	char d[MAX][MAX][MAX];
	bool marc[MAX][MAX][MAX];
	int nivel[MAX][MAX][MAX];
	Cel s, e, cel, celaux;
	queue<Cel> f;
	
	while(1)
	{
	   f = queue<Cel> ();
	   
		scanf("%d %d %d", &l, &r, &c);
		if(!l && !r && !c)
			break;
		getchar();
		
		for(int i=0; i<l; ++i)
		{
			for(int j=0; j<r; ++j)
			{
				for(int k=0; k<c; ++k)
				{
					scanf("%c", &d[i][j][k]);
					
					if(d[i][j][k] == 'S')
					{
						s.i = i;
						s.j = j;
						s.k = k;
					}
					else if(d[i][j][k] == 'E')
					{
						e.i = i;
						e.j = j;
						e.k = k;
					}
					
					if(d[i][j][k] == '#')
						marc[i][j][k] = 1;
					else
						marc[i][j][k] = 0;
				}
				getchar();
			}
			getchar();
		}
		
		for(int i=0; i<l; ++i)
			for(int j=0; j<r; ++j)
				for(int k=0; k<c; ++k)
					nivel[i][j][k] = -1;
					
		int viz[6][3] = {{0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}};
		
		f.push(s);
		nivel[s.i][s.j][s.k] = 0;
		marc[s.i][s.j][s.k] = 1;
		
		while(!f.empty())
		{
			cel = f.front();
			f.pop();
			
			if((cel.i == e.i) && (cel.j == e.j) && (cel.k == e.k))
				break;
			
			for(int k=0; k<6; ++k)
			{
				int iaux = cel.i + viz[k][0];
				int jaux = cel.j + viz[k][1];
				int kaux = cel.k + viz[k][2];
				
				if(in(iaux, jaux, kaux) && !marc[iaux][jaux][kaux])
				{
					celaux.i = iaux;
					celaux.j = jaux;
					celaux.k = kaux;
					
					f.push(celaux);
					
					marc[iaux][jaux][kaux] = 1;
					
					nivel[iaux][jaux][kaux] = nivel[cel.i][cel.j][cel.k] + 1;
				}
			}
		}
		
		if(nivel[e.i][e.j][e.k] == -1)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n", nivel[e.i][e.j][e.k]);
	}
	
	return 0;
}