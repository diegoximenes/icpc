#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cctype>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 20

struct state
{
	vector<int> c;
	int x, y;
	bool operator<(const state st) const
	{
		if(c != st.c) return (c < st.c);
		if(x != st.x) return (x < st.x);
		return (y < st.y);
	}
	state(int nx = 0, int ny = 0)
	{
		x = nx; y = ny;
		for(int i=0; i<6; ++i) c.pb(i);
	}
};

int n, m;
set<state> mark;
map<state, int> dist;
bool wall[MAX][MAX][MAX][MAX];
queue<state> q;

vector<int> rotateRight(vector<int> c)
{
	vector<int> r;
	r.assign(6, 0);
	r[0] = c[5]; r[1] = c[3]; r[2] = c[2]; r[3] = c[0]; r[4] = c[4]; r[5] = c[1];
	return r;
}

vector<int> rotateLeft(vector<int> c)
{
	vector<int> r;
	r.assign(6, 0);
	r[0] = c[3]; r[1] = c[5]; r[2] = c[2]; r[3] = c[1]; r[4] = c[4]; r[5] = c[0];
	return r;
}

vector<int> rotateFront(vector<int> c)
{
	vector<int> r;
	r.assign(6, 0);
	r[0] = c[2]; r[1] = c[4]; r[2] = c[1]; r[3] = c[3]; r[4] = c[0]; r[5] = c[5];
	return r;
}

vector<int> rotateBack(vector<int> c)
{
	vector<int> r;
	r.assign(6, 0);
	r[0] = c[4]; r[1] = c[2]; r[2] = c[0]; r[3] = c[3]; r[4] = c[1]; r[5] = c[5];
	return r;
}

inline bool can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<m) return 1;
	return 0;
}

inline void newState(state st, state nst)
{
	if(can(nst.x, nst.y) && !wall[st.x][st.y][nst.x][nst.y] && mark.find(nst) == mark.end())
	{
		q.push(nst);
		dist[nst] = dist[st] + 1;
		mark.insert(nst);
	}
}

void print(state st)
{
	printf("x= %d, y= %d, c= ", st.x, st.y);
	for(int i=0; i<6; ++i) printf("%d, ", st.c[i]);
	puts("");
}

int main()
{
	int sx, sy, tx, ty, x, y;
	char line[100];

	memset(wall, 0, sizeof(wall));

	scanf("%d %d %d %d %d %d", &n, &m, &sx, &sy, &tx, &ty);
	--sx; --sy; --tx; --ty;
	gets(line);
	
	bool hor = 1;
	while(1)
	{
		if(gets(line) == NULL) break;

		if(isalpha(line[0]))
		{
			if(line[0] == 'h') hor = 1;
			else hor = 0;
		}
		else
		{
			sscanf(line, "%d %d", &x, &y);
			--x; --y; //swap(x, y);
			if(!hor) wall[x][y][x+1][y] = wall[x+1][y][x][y] = 1;
			else wall[x][y+1][x][y] = wall[x][y][x][y+1] = 1;
		}
	}

	state s(sx, sy), t(tx, ty), tst;

	bool solved = 0;
	q.push(s); dist[s] = 0; mark.insert(s);
	while(!q.empty())
	{
		state st = q.front(); q.pop();
		//print(st);
		if(st.c[0] == s.c[0] && t.x == st.x && t.y == st.y)
		{
			tst = st;
			solved = 1;
			break;
		}

		state nst;
		nst.c = rotateRight(st.c);
		nst.x = st.x; nst.y = st.y + 1;
		newState(st, nst);

		nst.c = rotateLeft(st.c);
		nst.x = st.x; nst.y = st.y - 1;
		newState(st, nst);

		nst.c = rotateFront(st.c);
		nst.x = st.x + 1; nst.y = st.y;
		newState(st, nst);

		nst.c = rotateBack(st.c);
		nst.x = st.x - 1; nst.y = st.y;
		newState(st, nst);
	}
	if(solved) printf("%d\n", dist[tst]);
	else puts("No solution");

	return 0;
}
