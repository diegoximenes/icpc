#include<cstdio>
#include<cstring>
using namespace std;

int n;
char type, alg[110], line[200], braille[300][3][2];
const char baseBraille[10][3][2] = {
								{{'.','*'}, {'*', '*'}, {'.', '.'}},
							 	{{'*', '.'}, {'.', '.'}, {'.', '.'}},
								{{'*', '.'}, {'*', '.'}, {'.', '.'}},
								{{'*', '*'}, {'.', '.'}, {'.', '.'}},
								{{'*', '*'}, {'.', '*'}, {'.', '.'}},
								{{'*', '.'}, {'.', '*'}, {'.', '.'}},
								{{'*', '*'}, {'*', '.'}, {'.', '.'}},
								{{'*', '*'}, {'*', '*'}, {'.', '.'}},
								{{'*', '.'}, {'*', '*'}, {'.', '.'}},
								{{'.', '*'}, {'*', '.'}, {'.', '.'}},
							 };


inline bool cmp(int i, int j)
{
	for(int k=0; k<3; ++k)
		if(baseBraille[j][k][0] != braille[i][k][0] || baseBraille[j][k][1] != braille[i][k][1])
			return 0;
	return 1;
}

int main()
{
	while(scanf("%d", &n) && n)
	{
		scanf(" %c", &type);
		if(type == 'S')
		{
			scanf(" %s", alg);
			for(int j=0; j<3; ++j)
				for(int i=0; i<n; ++i)
				{
					printf("%c%c", baseBraille[alg[i] - '0'][j][0], baseBraille[alg[i] - '0'][j][1]);
					if(i == n-1) puts("");
					else putchar(' ');
				}
		}
		else
		{
			gets(line);
			for(int i=0; i<3; ++i)
				for(int j=0; j<n; ++j)
					scanf("%c%c%*c", &braille[j][i][0], &braille[j][i][1]);
			
			for(int i=0; i<n; ++i)
				for(int j=0; j<10; ++j)
					if(cmp(i, j))
					{
						printf("%d", j);
						break;
					}
			puts("");
		}
	}

	return 0;
}

