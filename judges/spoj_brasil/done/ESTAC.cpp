#include<cstdio>
#include<utility>
using namespace std;

#define MAX 1000
#define MAX2 10000

#define mp make_pair

void print(int *e, int n, int count)
{
	printf("count= %d\n", count);
	for(int i=0; i<n; ++i)
		printf("(%d, %d)  ", i, e[i]);
	puts("");
}

int main()
{
	int empty[MAX], c, n, p, w, count;
	char line[100], op;
	pair<int, int> car[MAX2];
	
	while(scanf("%d %d", &c, &n) == 2)
	{
		count = 0;
		for(int i=0; i<c; ++i)
			empty[i] = c-i;
		getchar();
		while(n--)
		{
			gets(line);
			sscanf(line, "%c %d", &op, &p);
			if(op == 'S')
			{
				int rightEmpty = 0;
				int right = car[p].first + car[p].second;
				if(right < c)
					rightEmpty = empty[right];
				for(int i=0; i<car[p].second; ++i)
					empty[car[p].first + i] = rightEmpty + car[p].second-i;
				for(int i=car[p].first-1, j=1; i>=0 && empty[i]!=0; --i, ++j)
					empty[i] = empty[car[p].first] + j;
			}
			else
			{
				sscanf(line, "%*c %*d %d", &w);
				for(int i=0; i<=c-w; ++i)
					if(empty[i] >= w)
					{
						car[p] = mp(i, w);
						for(int j=i; j<i+w; ++j)
							empty[j] = 0;
						for(int j=i-1; j>=0 && empty[j]!=0; --j)
							empty[j] = i-j;							
						count += 10;
						break;
					}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}
