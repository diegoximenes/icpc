#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1000000000

bool in(int i, int j)
{
	if(i>=0 && i<8 && j>=0 && j<8)
		return 1;
	return 0;
}

int main()
{
	int viz[8][2] = {{-2, 1}, {-1, 2}, {2, 1}, {1, 2}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
	int s, t, x, y, dist[64][64];
	vector< vector<int> > g;
	vector<int> v;
	char str1[5], str2[5];
	
	v.clear();
	g.assign(64, v);
	
	for(int i=0; i<8; ++i)
		for(int j=0; j<8; ++j)
			for(int k=0; k<8; ++k)
			{
				x = viz[k][0] + i;
				y = viz[k][1] + j;
				
				if(in(x, y))
					g[i*8 + j].push_back(x*8 + y);
			}
	
	for(int i=0; i<64; ++i)
			for(int j=0; j<64; ++j)
			{
				if(i == j)
					dist[i][j] = 0;
				else
					dist[i][j] = INF;
			}
		
	for(int i=0; i<64; ++i)
		for(int j=0; j<g[i].size(); ++j)
			dist[i][g[i][j]] = 1;
		
	for(int k=0; k<64; ++k)
		for(int i=0; i<64; ++i)
			for(int j=0; j<64; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);		
	
	while(scanf("%s %s", str1, str2) != EOF)
	{
		s = (str1[1] - '1')*8 + (str1[0] - 'a');
		t = (str2[1] - '1')*8 + (str2[0] - 'a');
		printf("To get from %c%c to %c%c takes %d knight moves.\n", str1[0], str1[1], str2[0], str2[1], dist[s][t]);
	}
	
	return 0;
}