#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 55
#define HASHMAX 500000

int n, cntPersons, hash[MAX][MAX][MAX][MAX];
double dp[MAX][HASHMAX];

bool cmp(const int &a, const int &b) { return (a > b); }

double opt(int a, vector<int> v)
{
	sort(v.begin(), v.end(), cmp);

	int cntVotes = a;
	for(int i=0; i<n; ++i) cntVotes += v[i];
	if(cntVotes == cntPersons)
	{ 
		if(a > v[0]) return 1.0;
		else if(a == v[0])
		{
			int cntMax = 1;
			for(int i=0; i<n; ++i)
				if(v[i] == a)
					cntMax++;
			return 1.0/(double)cntMax;
		}
		return 0.0;
	}

	double &state = dp[a][hash[v[0]][v[1]][v[2]][v[3]]];
	if(state >= 0.0) return state;
	
	double sol = (double)a/(double)cntVotes * opt(a+1, v);
	for(int i=0; i<n; ++i)
	{
		v[i]++;
		sol += (double)(v[i]-1)/(double)cntVotes * opt(a, v);
		v[i]--;
	}

	return state = sol;
}

int main()
{
	while(scanf("%d %d", &n, &cntPersons) == 2)
	{
		vector<int> v;
		for(int i=0; i<n; ++i)
		{
			int x; 
			scanf("%d", &x);
			v.pb(x);
		}

		int cntHash = 0;
		for(int i=cntPersons; i>=0; --i)
			for(int j=0; i+j<=cntPersons && j<=i; ++j)
				for(int k=0; i+j+k<=cntPersons && k<=j; ++k)
					for(int l=0; i+j+k+l<=cntPersons && l<=k; ++l)
						hash[i][j][k][l] = cntHash++;

		for(int j=0; j<=cntPersons; ++j)
			for(int k=0; k<=cntHash; ++k)
				dp[j][k] = -1;

		for(int i=0; i<n; ++i)
		{
			vector<int> vaux;
			for(int j=0; j<n; ++j)
				if(i != j)
					vaux.pb(v[j]);
			for(int j=n-1; j<=4; ++j) vaux.pb(0);
			
			printf("pub %d: %.2lf %c\n", i+1, opt(v[i], vaux) * 100.0, '%');
		}
	}

	return 0;
}
