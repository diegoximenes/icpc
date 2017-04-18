#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define pb push_back

vector<int> initial, end;
set< vector<int> > mark;

bool solve(vector<int> state)
{
	/*printf("state= \n");
	for(int i=0; i<(int)state.size(); ++i) printf("%d, ", state[i]);
	puts("");*/
	
	if(state.size() < end.size() || mark.find(state) != mark.end()) return 0;
	if(state.size() == end.size())
	{
		if(state == end) return 1;
		reverse(state.begin(), state.end());
		return (state == end);
	}
	mark.insert(state);

	for(int i=1; i<(int)state.size(); ++i)
	{
		vector<int> next;
		if(i <= (int)state.size()/2)
		{
			for(int j=i; j<(int)state.size(); ++j) next.pb(state[j]);
			for(int j=i-1, k=0; j>=0; --j, ++k) next[k] += state[j];
			reverse(next.begin(), next.end());
		}
		else
		{
			for(int j=0; j<i; ++j) next.pb(state[j]);
			for(int j=i-1, k=i; k<(int)state.size(); ++k, --j) next[j] += state[k];
		}

		bool sol = solve(next);
		if(sol) return 1;
	}
	return 0;
}

int main()
{
	int n, m, x;

	while(scanf("%d", &n) == 1)
	{
		mark.clear();
		initial.clear(); end.clear();
		for(int i=0; i<n; ++i) scanf("%d", &x), initial.pb(x);
		scanf("%d", &m);
		for(int i=0; i<m; ++i) scanf("%d", &x), end.pb(x);
		
		if(solve(initial)) puts("S");
		else puts("N");
	}

	return 0;
}
