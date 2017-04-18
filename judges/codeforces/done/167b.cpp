#include<bits/stdc++.h>
using namespace std;

#define MAX 205

struct Tour
{
	double p;
	int prize;
	Tour(double p=0, int prize=0) : p(p), prize(prize) {}
	bool operator<(const Tour &o) const
	{
		return (prize > o.prize);
	}
};

int n, minTours, homeBag;
double dp[MAX][MAX][MAX];
Tour tour[MAX];

double opt(int i, int wonTours, int bagCap)
{
	if(bagCap < 0) return 0.0;
	if(i == n) return (wonTours >= minTours);
	double &state = dp[i][wonTours][bagCap];
	if(state > -1) return state;
	
	state = 0;
	if(tour[i].prize == -1) state += tour[i].p * opt(i+1, wonTours+1, bagCap-1) + (1.0 - tour[i].p) * opt(i+1, wonTours, bagCap);
	else state += tour[i].p * opt(i+1, wonTours+1, min(bagCap + tour[i].prize, MAX-1)) + (1.0 - tour[i].p) * opt(i+1, wonTours, bagCap);
	
	return state;
}

int main()
{
	int homeCap;
	scanf("%d %d %d", &n, &minTours, &homeCap);
	for(int i=0; i<n; ++i) scanf("%lf", &tour[i].p), tour[i].p /= 100.0;
	for(int i=0; i<n; ++i) scanf("%d", &tour[i].prize);
	sort(tour, tour+n);
		
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=n; ++j)
			for(int k=0; k<MAX; ++k)
				dp[i][j][k] = -1;

	printf("%.6lf\n", opt(0, 0, homeCap));

	return 0;
}
