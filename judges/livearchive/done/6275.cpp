#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

#define MAX 1000010

int v[MAX], n, x;

int cmp(const void *a, const void *b)
{
	return (*((int *)a) - *((int *)b));
}

int main()
{
	while(scanf("%d %d", &x, &n) == 2)
	{
		bool solved = 0;
		map<int, int> cnt;

		x *= 10000000;
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &v[i]);
			if(cnt.find(v[i]) == cnt.end()) cnt[v[i]] = 1;
			else cnt[v[i]]++;
		}
		
		sort(v, v+n);
		for(int i=0; i<n; ++i)
		{
			int key = x - v[i];
			int *p = (int *)bsearch(&key, v, n, sizeof(int), cmp);
			if(p != NULL)
			{
				if((*p == v[i] && cnt[v[i]] > 1) || *p != v[i])
				{
					printf("yes %d %d\n", v[i], *p);
					solved = 1;
					break;
				}
			}
		}

		if(!solved) puts("danger");
	}

	return 0;
}
