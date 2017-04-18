#include<cstdio>
using namespace std;

#define MAX 10005

int dset[MAX], bestDish[MAX];

void init(int n) { for(int i=0; i<n; ++i) dset[i] = i; }

int findSet(int i) { return ((dset[i] == i) ? i : (dset[i] = findSet(dset[i]))); }

bool sameSet(int i, int j) { return (findSet(i) == findSet(j)); }

void unionSet(int i, int j)
{
	if(sameSet(i, j)) return;
	
	if(bestDish[findSet(i)] > bestDish[findSet(j)]) dset[findSet(j)] = findSet(i);
	else if(bestDish[findSet(j)] > bestDish[findSet(i)]) dset[findSet(i)] = findSet(j);
}

int main()
{
	int t, n, q, op, x, y;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		init(n);
		for(int i=0; i<n; ++i) scanf("%d", &bestDish[findSet(i)]);

		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &op, &x); --x;
			if(op) printf("%d\n", findSet(x) + 1);
			else
			{
				scanf("%d", &y); --y;
				if(sameSet(x, y)) puts("Invalid query!");
				else unionSet(x, y);
			}
		}
	}

	return 0;
}
