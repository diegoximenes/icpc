#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

#define pb push_back
#define MAXL 60
#define MAXT 100010
#define MAXLENP 1010
#define MAXP 1010

char t[MAXT], p[MAXLENP];
int countVertexes;

struct Vertex
{
	Vertex *letter[MAXL];
	int id;

	Vertex()
	{
		for(int i=0; i<MAXL; ++i) letter[i] = NULL;
		id = countVertexes++;
	}
};

Vertex* failure[MAXP*MAXLENP];
bool mark[MAXP*MAXLENP], match[MAXP];
vector<int> out[MAXP*MAXLENP];

void insert(Vertex *v, char *w, int len, int idPattern)
{
	if(v->letter[*w - 'A'] == NULL) v->letter[*w - 'A'] = new Vertex();
	if(len == 1) out[v->letter[*w - 'A']->id].pb(idPattern);
	else insert(v->letter[*w - 'A'], w + 1, len - 1, idPattern);
}

void freeMem(Vertex *v)
{
	for(int i=0; i<MAXL; ++i)
		if(v->letter[i] != NULL && v->letter[i] != v)
			freeMem(v->letter[i]);
	delete v;
}

void createFailureEdges(Vertex *root)
{
	queue<Vertex*> q;
	Vertex *u, *v;
	
	memset(mark, 0, sizeof(mark));
	for(int i=0; i<MAXL; ++i)
		if(root->letter[i] == NULL)
			root->letter[i] = root;
	
	failure[root->id] = root;
	for(int i=0; i<MAXL; ++i)
		if(root->letter[i] != NULL && !mark[root->letter[i]->id])
		{
			q.push(root->letter[i]);
			mark[root->letter[i]->id] = 1;
			failure[root->letter[i]->id] = root;
		}
	
	while(!q.empty())
	{
		v = q.front(); q.pop();
		for(int i=0; i<MAXL; ++i)
		{
			if(v->letter[i] != NULL && !mark[v->letter[i]->id])
			{
				q.push(v->letter[i]);
				mark[v->letter[i]->id] = 1;
				u = failure[v->id];
				while(u->letter[i] == NULL) u = failure[u->id];
				failure[v->letter[i]->id] = u->letter[i];
				for(int j=0; j<(int)out[failure[v->letter[i]->id]->id].size(); ++j)
					out[v->letter[i]->id].pb(out[failure[v->letter[i]->id]->id][j]);
			}
		}
	}
}

void search(Vertex *v)
{
	int len = strlen(t);
	for(int i=0; i<len; ++i)
	{
		while(v->letter[t[i]-'A'] == NULL) v = failure[v->id];
		v = v->letter[t[i]-'A'];
		if(!out[v->id].empty())
		{
			for(int j=0; j<(int)out[v->id].size(); ++j) match[out[v->id][j]] = 1;
			//found s at position i
		}
	}
}

int main()
{
	int tc, q;
	Vertex *v;
	
	scanf("%d", &tc);
	while(tc--)
	{
		scanf(" %s %d", t, &q);
		
		v = new Vertex();
		memset(match, 0, sizeof(match));
		for(int i=0; i<MAXP*MAXLENP; ++i) out[i].clear();
		for(int i=0; i<q; ++i)
		{
			scanf(" %s", p);
			insert(v, p, strlen(p), i);
		}
		createFailureEdges(v);
		search(v);

		for(int i=0; i<q; ++i) puts(match[i] ? "y" : "n");
		
		freeMem(v);
	}
	
	return 0;
}
