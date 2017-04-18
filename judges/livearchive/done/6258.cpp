#include<cstdio>
#include<set>
#include<map>
using namespace std;

#define mp make_pair
#define MAX 200010
#define INF (int) 1e9

class cmp
{
	public:
	bool operator()(const int a, const int b) const
	{
		return (a > b);
	}
};

int t, v[MAX], n, next[MAX], last[MAX], cnt;
map<int, int> dic;
set<int> treeHigh[MAX];
set<int, cmp> treeLow[MAX];
set<int>::iterator it;

bool solve(int begin, int end)
{
	if(begin >= end) return 1;
	bool left = 1;
	int actual;
	for(int k=0, i=0, j=0; k<=(end - begin); ++k)
	{
		if(left) actual = begin + i, ++i, left = 0;
		else actual = end - j, ++j, left = 1;
		
		//printf("begin= %d, end= %d, actual= %d, k= %d, i=%d, j= %d, left= %d\n", begin, end, actual, k, i, j, left);

		if(last[actual] < begin && next[actual] > end)
			return (solve(begin, actual-1) && solve(actual+1, end));
	}
	return 0;
}


int main()
{
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0; i<cnt; ++i) treeHigh[i].clear(), treeLow[i].clear();
		dic.clear();
		cnt = 0;
			
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &v[i]);
			if(dic.find(v[i]) == dic.end()) dic[v[i]] = cnt++;
			treeHigh[dic[v[i]]].insert(i);
			treeLow[dic[v[i]]].insert(i);
		}
		
		for(int i=0; i<n; ++i)
		{
			int ind = dic[v[i]];
			
			it = treeLow[ind].upper_bound(i);
			if(it == treeLow[ind].end()) last[i] = -1;
			else last[i] = *it;

			it = treeHigh[ind].upper_bound(i);
			if(it == treeHigh[ind].end()) next[i] = INF;
			else next[i] = *it;

			//printf("i= %d, v[i]= %d, last[i]= %d, next[i]= %d\n", i, v[i], last[i], next[i]);
		}

		if(solve(0, n-1)) puts("non-boring");
		else puts("boring");
	}

	return 0;
}
