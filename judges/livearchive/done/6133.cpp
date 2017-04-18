#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

#define MAXL 26

struct Vertex
{
	Vertex *letter[MAXL];
	int count;
	bool end;

	Vertex()
	{
		for(int i=0; i<MAXL; ++i)
			letter[i] = NULL;
		count = 0;
		end = 0;
	}
};

void insert(Vertex *v, char *w, int len)
{
	if(v->letter[*w - 'a'] == NULL)
	{
		v->letter[*w - 'a'] = new Vertex;
		++v->count;
	}
	if(len == 1)
		v->letter[*w - 'a']->end = 1;
	else
		insert(v->letter[*w - 'a'], w + 1, len - 1);
}

void freeMem(Vertex *v)
{
	for(int i=0; i<MAXL; ++i)
		if(v->letter[i] != NULL)
			freeMem(v->letter[i]);
	delete v;
}

int keyStrokes(Vertex *v, string str, int ind)
{
	if(ind == (int)str.size())
		return 0;
	if(v->count == 1)
	{
		for(int i=0; i<MAXL; ++i)
			if(v->letter[i] != NULL)
				return keyStrokes(v->letter[i], str, ind+1) + (v->end ? 1 : 0);
	}
	else
		return 1 + keyStrokes(v->letter[str[ind] - 'a'], str, ind+1);
}

int main()
{
	int n, len;
	char word[100];
	vector<string> dic;

	while(gets(word) != NULL)
	{
		Vertex *v = new Vertex;
		dic.clear();
		sscanf(word, "%d", &n);
		while(n--)
		{
			gets(word);
			len = strlen(word);
			dic.push_back(word);
			insert(v, word, len);
		}
		
		int count = 0;
		for(int i=0; i<(int)dic.size(); ++i)
			count += 1 + keyStrokes(v->letter[dic[i][0] - 'a'], dic[i], 1);
		printf("%.2lf\n", (double)count/(double)dic.size());
		
		freeMem(v);
	}
	
	return 0;
}
