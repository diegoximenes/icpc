#include<cstdio>
#include<stack>
using namespace std;

typedef long long ll;
#define mp make_pair
#define MAX 100005

int left[MAX], right[MAX], v[MAX];

int main()
{
	int n;

	while(scanf("%d", &n) && n)
	{	
		for(int i=0; i<n; ++i) scanf("%d", &v[i]);

		stack< pair<int, int> > s;
		for(int i=0; i<n; ++i)
		{
			while(!s.empty() && s.top().first >= v[i]) s.pop();
			if(!s.empty()) left[i] = s.top().second + 1;
			else left[i] = 0;
			s.push(mp(v[i], i));
		}
		
		while(!s.empty()) s.pop();
		for(int i=n-1; i>=0; --i)
		{
			while(!s.empty() && s.top().first >= v[i]) s.pop();
			if(!s.empty()) right[i] = s.top().second - 1;
			else right[i] = n-1;
			s.push(mp(v[i], i));
		}
		
		ll sol = 0;
		for(int i=0; i<n; ++i) sol = max(sol, (ll)v[i]*((ll)right[i] - (ll)left[i] + 1LL));
		printf("%lld\n", sol);
	}

	return 0;
}
