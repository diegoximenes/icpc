#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

#define MAX 5005

int countSet, set[MAX], size[MAX];

void init(int n)
{
	for(int i=0; i<n; ++i)
	{
		set[i] = i;
		size[i] = 1;
		countSet = n;
	}
}

int find(int i)
{
	return (set[i] == i) ? i : (set[i] = find(set[i]));
}

bool isSameSet(int i, int j)
{
	return find(i) == find(j);
}

void unionSet(int i, int j)
{
	if(isSameSet(i, j)) return;
	size[find(j)] += size[find(i)];
	set[find(i)] = find(j);
	--countSet;
}

int setSize(int i)
{
	return size[find(i)];
}

int main()
{
	int n, m;
	map<string, int> dic;
	char anim1[35], anim2[35];

	while(scanf("%d %d", &n, &m) && n)
	{
		init(n);
		dic.clear();

		for(int i=0; i<n; ++i)
		{
			scanf(" %s", anim1);
			dic[anim1] = i;
		}
		while(m--)
		{
			scanf(" %s %s", anim1, anim2);
			unionSet(dic[anim1], dic[anim2]);
		}

		int maxsize = -1;
		for(int i=0; i<n; ++i)
			maxsize = max(maxsize, setSize(i));
		printf("%d\n", maxsize);
	}

	return 0;
}
