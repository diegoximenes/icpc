#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define MAX 100005

int size, n;
int dp[MAX], id[MAX];
pair<int, int> tree[4*MAX];
ll h[MAX], haux[MAX], d;

void update(int node, int begin, int end, int pos, pair<int, int> value)
{
	if(begin == end) tree[node] = value;
	else
	{
		int mid = (begin + end)/2, nodeLeft = 2*node, nodeRight = 2*node+1;
		if(pos <= mid) update(nodeLeft, begin, mid, pos, value);
		else update(nodeRight, mid+1, end, pos, value);

		if(tree[nodeLeft].first > tree[nodeRight].first) tree[node] = tree[nodeLeft];
		else tree[node] = tree[nodeRight];
	}
}

pair<int, int> query(int node, int begin, int end, int left, int right)
{
	if((begin >= left) && (end <= right)) return tree[node];
	
	int mid = (begin + end)/2, nodeLeft = 2*node, nodeRight = 2*node+1;
	
	pair<int, int> ret = mp(-INF, -1);
	if(mid>=left && begin<=right)
	{
		pair<int, int> q = query(nodeLeft, begin, mid, left, right);
		if(q.first > ret.first) ret = q; 
	}
	if(end>=left && mid+1<=right)
	{
		pair<int, int> q = query(nodeRight, mid+1, end, left, right);
		if(q.first > ret.first) ret = q;
	}

	return ret;
}

void update(int pos, pair<int, int> value) { update(1, 1, size, pos, value); }
pair<int, int> query(int left, int right) { return query(1, 1, size, left, right); }

int main()
{
	cin >> n >> d;
	for(int i=1; i<=n; ++i) cin >> h[i], haux[i] = h[i];
	size = n;	
	
	sort(haux+1, haux+n+1);
	map<ll, deque<int> > hashDeque;
	map< pair<ll, int>, int>  hash, hash2;
	map< pair<ll, int>, int>::iterator it;
	for(int i=1; i<=n; ++i)
	{
		hash[mp(haux[i], i)] = i; 
		hash2[mp(-haux[i], -i)] = -i;
		hashDeque[haux[i]].push_back(i);
	}
	for(int i=1; i<=n; ++i) id[i] = hashDeque[h[i]].back(), hashDeque[h[i]].pop_back();
		
	memset(tree, 0, sizeof(tree));
	int sol = 0;
	for(int i=1; i<=n; ++i)
	{
		int lsol = 0;

		it = hash.lower_bound(mp(h[i] + d, -1));
		if(it != hash.end()) lsol = max(lsol, 1 + query(it->second, size).first);

		it = hash2.lower_bound(mp(-(h[i]-d), -INF));
		if(it != hash2.end()) lsol = max(lsol, 1 + query(1, -it->second).first);
		
		dp[i] = lsol;
		sol = max(sol, dp[i]);
		update(id[i], mp(dp[i], i));
	}
	
	//rebuild	
	vector<int> out;
	int lsol = sol, lasti = n, i;
	for(i=n; i>=0 && dp[i] != sol; --i);
	while(lsol)	
	{
		lsol--;
		out.pb(i);

		for(int j=lasti; j>=i; --j) update(id[j], mp(0, j));
		lasti = i;

		it = hash.lower_bound(mp(h[i] + d, -INF));
		if(it != hash.end() && dp[i] == 1 + query(it->second, size).first) i = query(it->second, size).second;
		else
		{
			it = hash2.lower_bound(mp(-(h[i]-d), -INF));
			if(it != hash2.end()) i = query(1, -it->second).second;
		}
	}
				
	sort(out.begin(), out.end());
	cout << sol << endl << out[0];
	for(int j=1; j<(int)out.size(); ++j) cout << " " << out[j];
	cout << endl;

	return 0;
}
