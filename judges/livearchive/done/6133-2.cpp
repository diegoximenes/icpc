/*
Tested with: live archive 6133
*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define LMAX ('z'-'a'+1)
#define NMAX 500005 //max number of vertexes, think how to guess this number

int trie[NMAX][LMAX], nv;
bool isEnd[NMAX]; //1 if this vertex is a word end
char word[NMAX];

inline int ind(char c) { return (c - 'a'); } 

void insert(char *s)
{
	int len = strlen(s), u = 0;
	for(int i=0; i<len; ++i)
	{
		if(trie[u][ind(s[i])] == -1) trie[u][ind(s[i])] = ++nv;
		u = trie[u][ind(s[i])];
	}
	isEnd[u] = 1;
}

int keyStrokes(int u, int i, string &s)
{
	if(i == (int)s.size()) return 0;

	int cntChild = 0;
	for(int j=0; j<LMAX; ++j)
		if(trie[u][j] != -1)
			++cntChild;

	int sol = keyStrokes(trie[u][ind(s[i])], i+1, s);
	if(cntChild > 1 || isEnd[u]) sol++;

	return sol;
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		nv = 0;
		memset(isEnd, 0, sizeof(isEnd));
		memset(trie, -1, sizeof(trie));
		
		vector<string> v;
		while(n--)
		{
			scanf(" %s ", word);
			v.pb(word);
			insert(word);
		}

		int cnt = 0;
		for(int i=0; i<(int)v.size(); ++i) cnt += 1 + keyStrokes(trie[0][ind(v[i][0])], 1, v[i]);
		printf("%.2lf\n", (double)cnt/(double)v.size());
	}

	return 0;
}
