#include<cstdio>
#include<set>
#include<cstring>
using namespace std;

#define MAX 105
#define INF 1e9

#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))

int maxdigits = -INF;

void combination(int *v, int *mark, int size, int level, int n)
{
	if(level == size)
	{
		int digit[MAX];
		set<int> s;
		
		for(int i=0; i<n; ++i)
			digit[i] = v[i];
		
		for(int i=0; i<size; ++i)
			if(mark[i])
				for(int j=0; j<n; ++j)
					clearBit(digit[j], i);
				
		for(int i=0; i<n; ++i)
		{
			if(s.find(digit[i]) != s.end())
				return;
			s.insert(digit[i]);
		}
		int count = 0;
		for(int i=0; i<n; ++i)
			if(mark[i])
				++count;
		maxdigits = max(count, maxdigits);
	}
	else
	{
		mark[level] = 1;
		combination(v, mark, size, level + 1, n);
		mark[level] = 0;
		combination(v, mark, size, level + 1, n);
	}
}

int main()
{
	int t, digit[MAX], mark[MAX];
	
	scanf("%d", &t);
	while(t--)
	{	
		int l, n;
		scanf("%d %d", &l, &n);
		memset(digit, 0, n*sizeof(int));
		for(int i=0; i<n; ++i)
			for(int j=0; j<l; ++j)
			{
				int d;
				scanf("%d", &d);
				if(d)
					setBit(digit[i], j);
			}
		
		maxdigits = -INF;
		memset(mark, 0, n*sizeof(int));
		combination(digit, mark, l, 0, n);
		
		printf("%d\n", l-maxdigits);
	}
	
	return 0;
}