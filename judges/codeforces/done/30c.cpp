#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 1005

struct Target
{
	int x, y, t;
	double p;
	Target(int x=0, int y=0, int t=0, double p=0.0) : x(x), y(y), t(t), p(p) {}
	bool operator<(const Target &o) const
	{
		return (t < o.t);
	}
};

int n;
double dp[MAX];
vector<int> next[MAX];
Target target[MAX];

double opt(int i)
{
	if(i == n) return 1.0;
	double &state = dp[i];
	if(state > -1) return state;

	state = target[i].p;
	for(int j=0; j<(int)next[i].size(); ++j) state = max(state, target[i].p + opt(next[i][j]));
	
	return state;
}

double dist(Target &t1, Target &t2) 
{ 
	return hypot(t1.x - t2.x, t1.y - t2.y); 
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d %d %d %lf", &target[i].x, &target[i].y, &target[i].t, &target[i].p);
	
	sort(target, target+n);
	for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
			if(dist(target[i], target[j]) <= (double)(target[j].t - target[i].t))
				next[i].pb(j);
		
	for(int i=0; i<=n; ++i) dp[i] = -1;

	double sol = 0;
	for(int i=0; i<n; ++i) sol = max(sol, opt(i));
	printf("%.6lf\n", sol);	

	return 0;
}
