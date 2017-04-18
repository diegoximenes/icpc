#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

#define setBit(S, j) (S |= (1 << j))
#define isOn(S, j) (S & (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))

#define MAX 35
#define INF 1e9

struct Vertex
{
	int v, w;
	Vertex(int v = 0, int w = 0): v(v), w(w) {}
};

vector<Vertex> g[MAX];
vector<int> licenses[MAX];
bool found;
int s, t, mincat, mark;

int count(int n, int k)
{
	int count = 0;
	for(int i=0; i<k; ++i)
		if(isOn(n, i))
			++count;
	return count;
}

void generatePath(int v, int cat)
{
	int u, w;
	
	setBit(mark, v);
	if(found)
		return;
	if(v == t) 
	{
		found = 1;
		return;
	}
	
	for(int i=0; i<(int)g[v].size(); ++i)
	{
		u = g[v][i].v; w = g[v][i].w;
		
		if(isOn(mark, u))
			continue;
		if(isOn(cat, w))
		{
			generatePath(u, cat);
			if(found)
				return;
		}
	}
}

bool test(int h)
{
	for(int i=0; i<(int)licenses[h].size(); ++i)
	{
		found = 0;
		mark = 0;
		generatePath(s, licenses[h][i]);
		if(found)
		{
			mincat = licenses[h][i];
			return 1;
		}
	}
	return 0;
}

int main()
{	
	int k, n, m, v, u, w, nlicenses;
	
	scanf("%d %d %d", &k, &n, &m);
	nlicenses = pow(2, k);
	
	while(m--)
	{
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(Vertex(v, w));
		g[v].push_back(Vertex(u, w));
	}
	s = 1; t = 0;
	
	//gera licenças
	for(int i=1; i<nlicenses; ++i)
		licenses[count(i, k)].push_back(i);
	
	int l=1, h=k;
	while(h - l > 1)
	{
		int mid = (l+h)/2;
		for(int i=0; i<(int)licenses[mid].size(); ++i)
		{
			found = 0;
			//verifica se existe caminho no grafo com essas licenças 
			mark = 0;
			generatePath(s, licenses[mid][i]);
			if(found)
				break;
		}
		if(found)
			h = mid;
		else
			l = mid;
	}
	
	int ncat = l;
	if(!test(l))
	{
		ncat = h;
		test(h);
	}

	printf("%d\n", ncat);
	bool first = 1; 
	for(int i=0; i<k; ++i)
		if(isOn(mincat, i))
		{
			if(first)
			{
				printf("%d", i);
				first = 0;
			}
			else
				printf(" %d", i);
		}
	puts("");
	
	
	return 0;
}