#include<cstdio>
#include<cstring>
using namespace std;

int main()
{	
	int g[9][9], n;
	bool alg[10];

	scanf("%d", &n);
	for(int tc=1; tc<=n; ++tc)
	{
		bool sol = 1;

		for(int i=0; i<9; ++i)
			for(int j=0; j<9; ++j)
				scanf("%d", &g[i][j]);
		
		//lines
		for(int i=0; i<9 && sol; ++i)
		{
			memset(alg, 0, sizeof(alg));
			for(int j=0; j<9 && sol; ++j)
			{
				if(alg[g[i][j]]) sol = 0;
				alg[g[i][j]] = 1;
			}
		}

		//columns
		for(int i=0; i<9 && sol; ++i)
		{
			memset(alg, 0, sizeof(alg));
			for(int j=0; j<9 && sol; ++j)
			{
				if(alg[g[j][i]]) sol = 0;
				alg[g[j][i]] = 1;
			}
		}

		for(int i=0; i<9 && sol; i+=3)
			for(int j=0; j<9 && sol; j+=3)
			{
				memset(alg, 0, sizeof(alg));
				for(int k=0; k<3 && sol; ++k)
					for(int l=0; l<3 && sol; ++l)
					{
						if(alg[g[i+k][j+l]]) sol = 0;
						alg[g[i+k][j+l]] = 1;
					}
			}

		printf("Instancia %d\n", tc);
		if(sol) puts("SIM\n");
		else puts("NAO\n");
	}

	return 0;
}
