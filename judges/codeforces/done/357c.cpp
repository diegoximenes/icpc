#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

#define MAX 300010

int main()
{
	int n, m, l, r, x, winner[MAX];
	set<int> s;
	set<int>::iterator it, itaux;
	
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i) s.insert(i);
	memset(winner, 0, sizeof(winner));
	
	for(int i=0; i<m; ++i)
	{
		scanf("%d %d %d", &l, &r, &x);
		itaux = it = s.lower_bound(l);
		
		for(; it != s.end() && *it <= r; ++it)
			if(*it != x)
				winner[*it] = x;
		s.erase(itaux, it);
		s.insert(x);
	}
	
	printf("%d", winner[1]);
	for(int i=2; i<=n; ++i) printf(" %d", winner[i]);
	puts("");

	return 0;
}
