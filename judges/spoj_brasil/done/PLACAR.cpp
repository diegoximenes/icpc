#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back
#define mp make_pair

bool cmp(pair<int, string> p1, pair<int, string> p2)
{
	if(p1.first == p2.first)
	{
		if(p2.second.compare(p1.second) < 0)
			return 1;
		return 0;
	}
	return p1.first < p2.first;
}

int main()
{
	int n, p;
	vector< pair<int, string> > v;
	char name[21];

	for(int tc=1; scanf("%d", &n) == 1; ++tc)
	{
		v.clear();
		for(int i=0; i<n; ++i)
		{
			scanf(" %s %d", name, &p);
			v.pb(mp(p, name));
		}
		sort(v.begin(), v.end(), cmp);
		
		printf("Instancia %d\n%s\n", tc, v[0].second.c_str());
	}
		
	return 0;
}
