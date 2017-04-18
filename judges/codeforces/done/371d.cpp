#include<cstdio>
#include<set>
using namespace std;

#define MAX 200010

int size[MAX], initial[MAX];

int main()
{
	int n, q, op, v, l;
	set<int> tree;
	set<int>::iterator it;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &size[i]), tree.insert(i), initial[i] = size[i];
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d", &op, &v);
		if(op == 1)
		{ 
			scanf("%d", &l);
			while(l > 0)
			{
				it = tree.upper_bound(v - 2);
				if(it == tree.end()) break;
				if(size[*it] > l) size[*it] -= l, l = 0;
				else
				{
					l -= size[*it];
					size[*it] = 0;
					tree.erase(it);
				}
			}
		}
		else printf("%d\n", initial[v-1] - size[v-1]);
	}

	return 0;
}
