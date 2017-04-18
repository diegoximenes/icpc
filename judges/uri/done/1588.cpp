#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define EPS 1e-7
#define MAX 105

struct Team
{
	int id, points, victories, goals;
	string name;

	Team(int id=0, int points=0, int victories=0, int goals=0) : id(id), points(points), victories(victories), goals(goals) {} ;
	bool operator<(Team o) const
	{
		if(points != o.points) return (points > o.points);
		if(victories != o.victories) return (victories > o.victories);
		if(goals != o.goals) return (goals > o.goals);
		return (id < o.id);
	}
};

int main()
{
	int t, n, m;
	char name1[MAX], name2[MAX];
	Team v[MAX];
	
	scanf("%d", &t);
	while(t--)
	{
		map<string, int> dic;

		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) v[i].goals = v[i].victories = v[i].points = 0;

		for(int i=0; i<n; ++i) scanf(" %s ", name1), dic[name1] = i, v[i].name = name1, v[i].id = i;
		
		for(int i=0; i<m; ++i) 
		{
			int g1, g2;
			scanf(" %d %s %d %s ", &g1, name1, &g2, name2);
			int id1 = dic[name1];
			int id2 = dic[name2];

			v[id1].goals += g1;
			v[id2].goals += g2;
			if(g1 > g2) v[id1].points += 3, v[id1].victories++;
			else if(g1 == g2) v[id1].points++, v[id2].points++;
			else v[id2].points += 3, v[id2].victories++;
		}

		sort(v, v+n);
		for(int i=0; i<n; ++i) printf("%s\n", v[i].name.c_str());
	}

	return 0;
}
