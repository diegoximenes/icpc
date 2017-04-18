#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define MAX2 1005
#define MAX MAX2*MAX2
#define RIGHT 0
#define UP 1

struct Query
{
	int type, x1, y1, x2, y2;
	Query(int _type=0, int _x1=0, int _y1=0, int _x2=0, int _y2=0) : type(_type), x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
};

int t, n, m, q;
int dset[MAX], dsetSize[MAX];
int maxDsetSize;
int cntEdge[MAX2][MAX2][2];
Query query[MAX];

inline int id(int i, int j) { return (i*m + j); }
inline bool can(int i, int j) { return (i>=0 && i<n && j>=0 && j<m); }

void init()
{
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
		{
			dset[id(i, j)] = id(i, j);
			dsetSize[id(i, j)] = 1;
		}
}
int findSet(int i) { return (dset[i] == i ? i : dset[i] = findSet(dset[i])); }
bool sameSet(int i, int j) { return (findSet(i) == findSet(j)); }
void unionSet(int i, int j)
{
	if(sameSet(i, j)) return;
	
	dsetSize[findSet(j)] += dsetSize[findSet(i)];
	maxDsetSize = max(maxDsetSize, dsetSize[findSet(j)]);
		
	dset[findSet(i)] = findSet(j);
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &q);
		
		init();
		maxDsetSize = 1;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				cntEdge[i][j][RIGHT] = cntEdge[i][j][UP] = 0;

		for(int i=0; i<q; ++i)
		{
			int type, x1, y1, x2, y2;
			
			scanf("%d", &type);
			if(type == 1 || type == 2) scanf("%d %d", &x1, &y1);
			else if(type == 3) scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			--x1; --y1; --x2; --y2;

			query[i] = Query(type, x1, y1, x2, y2);

			if(type == 1) cntEdge[x1][y1][RIGHT]++;
			else if(type == 2) cntEdge[x1][y1][UP]++;
		}

		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
			{
				if(can(i, j+1) && !cntEdge[i][j][RIGHT]) unionSet(id(i, j), id(i, j+1));
				if(can(i+1, j) && !cntEdge[i][j][UP]) unionSet(id(i, j), id(i+1, j));
			}
		
		ll sol = 0;
		for(int i=q-1; i>=0; --i)
		{
			int type = query[i].type, x1 = query[i].x1, y1 = query[i].y1, x2 = query[i].x2, y2 = query[i].y2;
			
			if(type == 1) 
			{
				cntEdge[x1][y1][RIGHT]--;
				if(!cntEdge[x1][y1][RIGHT]) unionSet(id(x1, y1), id(x1, y1+1));
			}
			else if(type == 2) 
			{
				cntEdge[x1][y1][UP]--;
				if(!cntEdge[x1][y1][UP]) unionSet(id(x1, y1), id(x1+1, y1));
			}
			else if(type == 3) sol += sameSet(id(x1, y1), id(x2, y2));
			else sol += maxDsetSize;
		}
		
		printf("%lld\n", sol);
	}

	return 0;
}
