#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

#define pb push_back
#define MAXL ('z'-'a'+1)
#define MAX 1000010

char t[MAX], p[MAX];
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

Vertex* failure[MAX];
bool mark[MAX], deleted[MAX];
vector<int> out[MAX];

void insert(Vertex *v, char *w, int len, int idPattern)
{
	if(v->letter[*w - 'a'] == NULL) v->letter[*w - 'a'] = new Vertex();
	if(len == 1) out[v->letter[*w - 'a']->id].pb(idPattern);
	else insert(v->letter[*w - 'a'], w + 1, len - 1, idPattern);
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

int search(Vertex *v, char *t)
{
	int len = strlen(t), ret = 0;
	for(int i=0; i<len; ++i)
	{
		while(v->letter[t[i]-'a'] == NULL) v = failure[v->id];
		v = v->letter[t[i]-'a'];
		if(!out[v->id].empty())
			for(int j=0; j<(int)out[v->id].size(); ++j) 
				if(!deleted[out[v->id][j]])
					++ret;
	}
	return ret;
}

int main()
{
	int n, q;
	Vertex *v = new Vertex();
	
	scanf("%d %d", &q, &n);
	for(int i=0; i<n; ++i)
	{
		scanf(" %s ", p);
		insert(v, p, strlen(p), i);
	}
	createFailureEdges(v);
	
	memset(deleted, 0, sizeof(deleted));	
	while(q--)
	{
		scanf(" %s ", t);

		if(t[0] == '?') printf("%d\n", search(v, t+1));
		else
		{
			char op; int id;
			sscanf(t, "%c%d", &op, &id); --id;
			if(op == '-') deleted[id] = 1;
			else deleted[id] = 0;
		}
	}
	
	freeMem(v);

	return 0;
}
