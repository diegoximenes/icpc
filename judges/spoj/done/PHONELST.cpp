#include<cstdio>
#include<cstring>
using namespace std;

#define MAXL 10

struct Vertex
{
	Vertex *letter[MAXL];
	bool end;
	int count;

	Vertex()
	{
		for(int i=0; i<MAXL; ++i)
			letter[i] = NULL;
		count = end = 0;
	}
};

void freeMem(Vertex *v)
{
	for(int i=0; i<MAXL; ++i)
		if(v->letter[i] != NULL)
			freeMem(v->letter[i]);
	delete v;
}

bool add(Vertex *v, char *w, int len)
{
	if(v->end)
		return 1;

	if(v->letter[*w - '0'] == NULL)
	{
		v->letter[*w - '0'] = new Vertex;
		++v->count;
	}
	if(len == 1)
	{
		if(v->letter[*w - '0']->count != 0 || v->letter[*w - '0']->end == 1)
			return 1;
		else
		{
			v->letter[*w - '0']->end = 1;		
			return 0;
		}
	}
	else
		return add(v->letter[*w - '0'], w+1, len-1);
}

int main()
{
	int t, n;
	bool prefix;
	char w[100];

	gets(w);
	sscanf(w, "%d", &t);
	while(t--)
	{
		Vertex *v = new Vertex;
		prefix = 0;

		gets(w);
		sscanf(w, "%d", &n);
		while(n--)
		{
			gets(w);
			if(!prefix)
				prefix = add(v, w, strlen(w));
		}
		if(!prefix)
			puts("YES");
		else
			puts("NO");

		freeMem(v);
	}

	return 0;
}
