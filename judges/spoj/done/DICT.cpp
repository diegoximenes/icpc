#include<cstdio>
#include<cstring>
using namespace std;

#define MAXL 26

struct Vertex 
{
	Vertex *letter[MAXL];
	bool end;
	
	Vertex()
	{
		for(int i=0; i<MAXL; ++i)
			letter[i] = NULL;
		end = 0;
	}
};

void add(Vertex *v, char *w, int len)
{
	if(v->letter[*w - 'a'] == NULL)
		v->letter[*w - 'a'] = new Vertex;
	
	if(len != 1)
		add(v->letter[*w - 'a'], w+1, len-1);
	else
		v->letter[*w - 'a']->end = 1;
}

void freeMem(Vertex *v)
{
	for(int i=0; i<MAXL; ++i)
		if(v->letter[i] != NULL)
			freeMem(v->letter[i]);
	delete v;
}

void search(Vertex *v, char *w, int indw, char *ans, int lenans, int lenw)
{
	if(indw > 0)
	{
		if(v->letter[*w - 'a'] != NULL)
		{
			ans[lenans] = *w;
			search(v->letter[*w - 'a'], w+1, indw-1, ans, lenans+1, lenw);
		}
		else
		{
			puts("No match.");
			return;
		}
	}
	else
	{
		if(v->end && lenans!=lenw)
		{
			for(int i=0; i<lenans; ++i)
				putchar(ans[i]);
			puts("");
		}
		for(int i=0; i<MAXL; ++i)
			if(v->letter[i] != NULL)
			{
				ans[lenans] = i + 'a';
				search(v->letter[i], w, indw, ans, lenans+1, lenw);
			}
	}
}

int main()
{
	int n, t;
	char w[30], ans[30];
	Vertex *v = new Vertex;
	
	gets(w);
	sscanf(w, "%d", &n);
	while(n--)
	{
		gets(w);
		add(v, w, strlen(w));
	}
	gets(w);
	sscanf(w, "%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		gets(w);
		printf("Case #%d:\n", tc);
		search(v, w, strlen(w), ans, 0, strlen(w));
	}

	freeMem(v);

	return 0;
}
