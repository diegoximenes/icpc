#include<cstdio>
#include<cstring>
using namespace std;

int score;
char g[100][100];
bool issolved;

bool in(int i, int j)
{
	if(i<0 || i>3 || j<0 || j>3)
		return 0;
	return 1;
}

void solve(int i, int j, char *w, int len, int level, bool mark[4][4])
{
	if(issolved)
		return;
	if(len == 0)
	{
		issolved = 1;
		if(level == 3 || level == 4)
			score = 1;
		else if(level == 5)
			score = 2;
		else if(level == 6)
			score = 3;
		else if (level == 7)
			score = 5;
		else if(level >= 8)
			score = 11;
		else
			score = 0;
	}
	else
	{
		for(int k=i-1; k<=i+1; ++k)
			for(int l=j-1; l<=j+1; ++l)
				if(in(k, l) && !(k == i && l == j) && !mark[k][l] && (w[0] == g[k][l]))
				{
					mark[k][l] = 1;
					solve(k, l, w+1, len-1, level+1, mark);
					if(issolved)
						return;
					mark[k][l] = 0;
				}
			
	}
}

int main()
{
	int m, n;
	bool mark[4][4];
	char w[18];
	
	gets(w); sscanf(w, "%d", &n);
	for(int t=1; t<=n; ++t)
	{
		gets(w);
		for(int i=0; i<4; ++i)
			gets(g[i]);

		
		int scoresum = 0;
		gets(w); sscanf(w, "%d", &m);
		while(m--)
		{
			char s[500];
			gets(s);
			sscanf(s, "%s", w);
			
			issolved = 0;
			for(int i=0; !issolved && i<4; ++i)
				for(int j=0; !issolved && j<4; ++j)
					if(w[0] == g[i][j])
					{
						for(int k=0; k<4; ++k)
							for(int l=0; l<4; ++l)
								mark[k][l] = 0;
						mark[i][j] = 1;
						solve(i, j, w+1, strlen(w)-1, 1, mark);
					}
			if(issolved)
				scoresum += score;
		}
		
		printf("Score for Boggle game #%d: %d\n", t, scoresum);
	}
	
	return 0;
}
