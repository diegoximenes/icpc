#include<cstdio>
#include<map>
using namespace std;

#define mp make_pair
#define MAX 1000010

pair<int, int> last[MAX];
int v[MAX];

int main()
{
	int n, q, l, r; 

	while(scanf("%d %d", &n, &q) && n)
	{
		map<int, int> tree;
		last[n-1].first = n;
		
		for(int i=0; i<n; ++i) scanf("%d", &v[i]);

		for(int i=n-1; i>=0; --i)
		{
			int x = v[i];

			if(tree.find(x) != tree.end() && i+1 < n && tree[x] < last[i+1].first) 
				last[i].first = tree[x], last[i].second = x;
			else if(i+1 < n) last[i] = last[i+1];
			
			//printf("i= %d, last[i].first= %d, last[i].second= %d, tree[x]= %d\n", i, last[i].first, last[i].second, tree[x]);
			
			tree[x] = i;
		}

		while(q--)
		{
			scanf("%d %d", &l, &r);
			--r; --l;
			if(last[l].first > r) puts("OK");
			else printf("%d\n", last[l].second);
		}

		puts("");
	}
}
