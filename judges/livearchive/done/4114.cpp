#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 10000

char tree[MAX], code[MAX];

void solve(int k, int l, int r)
{
	int countl = 0, countr = 0;
	
	if(l == r) 
	{ 
		putchar(tree[l]); 

		if(k == (int)strlen(code)) return;	
		else if((int)strlen(tree) == 1) return solve(k + 1, 0, 0);
		else return solve(k, 0, strlen(tree)-1); 
	}
	for(int i=l; i<=r; ++i)
	{
		if(tree[i] == '(') ++countl;
		else if(tree[i] == ')') ++countr;
		else if(tree[i] == ',' && countl == countr + 1)
		{
			if(code[k] == '1') return solve(k + 1, i + 1, (tree[r] == ')') ? r - 1: r);
			else return solve(k + 1, (tree[l] == '(') ? l + 1 : l, i - 1);
		}
	}
}

int main()
{
	int t, q;

	scanf("%d", &t);
	while(t--)
	{
		scanf(" %s %d", tree, &q);
		while(q--)
		{
			scanf(" %s", code);
			solve(0, 0, strlen(tree)-1);
			puts("");
		}
	}

	return 0;
}
