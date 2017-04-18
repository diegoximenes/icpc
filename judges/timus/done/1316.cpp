#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 1000001

int tree[MAX];

int read(int idx)
{
	int sum = 0;
	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int val)
{
	while(idx <= MAX-1)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int main()
{
	int b, k;
	char op[5];
	double v, sol = 0.0;
	
	memset(tree, 0, sizeof(tree));
	while(scanf(" %s %lf", op, &v) && strcmp(op, "QUIT") != 0)
	{
		b = (v + 1e-9)*100.0;
		//printf("v= %lf, b= %d, v*100.0= %lf", v, b, v*100.0);
		if(strcmp(op, "BID") == 0)
			update(b, 1);
		else if(strcmp(op, "SALE") == 0)
		{
			scanf("%d", &k);
			sol += 0.01*min(k, read(MAX-1) - read(b-1));
		}
		else 
			update(b, -1);

	}
	printf("%.2lf\n", sol);
		
	return 0;
}
