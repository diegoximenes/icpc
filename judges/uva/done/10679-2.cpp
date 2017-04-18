/*
Tested with: I Love Strings!! (uva 10679), GATTACA (uva 11512) 
*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define mp make_pair
#define MAXP 0
#define MAXT 1010
#define LOGMAX 20

char t[MAXT + MAXP]; //text: increase size of text by size of pattern if use match
char p[MAXP]; // patterm
int n; // text length
int m; // pattern length
int sortIndex[LOGMAX][MAXT];
pair< pair<int, int>, int > sa[MAXT];

//findLCP
int phi[MAXT], lcp[MAXT], plcp[MAXT];

//O(n*logn)
void buildSuffixArray()
{
	for(int i=0; i<n; ++i) sortIndex[0][i] = t[i] - 'A';
	
	for(int k = 1, step = 1; k < n; ++step, k*=2)
	{
		for(int i=0; i<n; ++i)
		{
			sa[i].first.first = sortIndex[step - 1][i];
			sa[i].first.second = (i + k < n) ? sortIndex[step - 1][i + k] : -1;
			sa[i].second = i;
		}
		
		sort(sa, sa + n);

		for(int i=0; i<n; ++i)
		{
			if(i > 0 && sa[i].first == sa[i - 1].first) sortIndex[step][sa[i].second] = sortIndex[step][sa[i - 1].second];
			else sortIndex[step][sa[i].second] = i;
		}
	}
}

//O(n)
void findLCP()
{
	int i, l;
	phi[sa[0].second] = -1;
	for(i = 1; i<n; ++i) phi[sa[i].second] = sa[i-1].second;
	for(i=l=0; i<n; ++i)
	{
		if(phi[i] == -1)
		{
			plcp[i] = 0;
			continue;
		}
		while(t[i + l] == t[phi[i] + l]) ++l;
		plcp[i] = l;
		l = max(l-1, 0);
	}
	for(i=1; i<n; ++i) lcp[i] = plcp[sa[i].second];
}

//O(m*logn)
pair<int, int> match()
{
	int l = 0, r = n-1, mid;
	
	while(l < r)
	{
		mid = (l + r)/2;
		int res = strncmp(t + sa[mid].second, p, m);
		if(res >= 0) r = mid;
		else l = mid + 1;
	}
	if(strncmp(t + sa[l].second, p, m) != 0) return mp(-1, -1);
	pair<int, int> sol; sol.first = l;

	l = 0; r = n - 1;
	while(l < r)
	{
		mid = (l + r)/2;
		int res = strncmp(t + sa[mid].second, p, m);
		if(res > 0) r = mid;
		else l = mid + 1;
	}
	if(strncmp(t + sa[r].second, p, m) != 0) r--;
	sol.second = r;
	
	return sol;
}

int main()
{
	int tc, q;

	scanf("%d", &tc);
	while(tc--)
	{
		scanf(" %s %d", t, &q);
		n = strlen(t); t[n++] = '$';
		
		buildSuffixArray();	
		while(q--)
		{
			scanf(" %s", p);
			m = strlen(p);

			if(match() != mp(-1, -1)) puts("y");
			else puts("n");
		}
	}
	
	return 0;
}
