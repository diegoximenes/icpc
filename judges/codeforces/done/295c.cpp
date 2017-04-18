#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 55
#define MOD 1000000007

struct Node
{
	int cnt50, cnt100, l;
	Node(int cnt50=0, int cnt100=0, int l=0) : cnt50(cnt50), cnt100(cnt100), l(l) {}
};

int dist[MAX][MAX][2], cntWays[MAX][MAX][2];
int dpComb[MAX][MAX];

int comb(int n, int k)
{
	if(k > n) return 0;
	if(n == k || k == 0) return 1;
	int &state = dpComb[n][k];
	if(state != -1) return state;

	return state = (comb(n-1, k) + comb(n-1, k-1))%MOD;
}

int main()
{
	int n, w, gcnt50=0, gcnt100=0;

	scanf("%d %d", &n, &w);
	for(int i=0; i<n; ++i)
	{
		int x; scanf("%d", &x);
		(x == 50) ? gcnt50++ : gcnt100++;
	}
		
	memset(dpComb, -1, sizeof(dpComb));
	memset(dist, -1, sizeof(dist));
	memset(cntWays, 0, sizeof(cntWays));

	Node s(gcnt50, gcnt100, 1);
	queue<Node> q; q.push(s);
	dist[s.cnt50][s.cnt100][s.l] = 0;
	cntWays[s.cnt50][s.cnt100][s.l] = 1;
	while(!q.empty())
	{
		Node node = q.front(); q.pop();
		
		int cnt50 = node.cnt50, cnt100 = node.cnt100;
		if(!node.l) cnt50 = gcnt50 - node.cnt50, cnt100 = gcnt100 - node.cnt100;
		
		//printf("cnt50= %d, cnt100= %d, l= %d, dist= %d, cntWays= %d\n", node.cnt50, node.cnt100, node.l, dist[node.cnt50][node.cnt100][node.l], cntWays[node.cnt50][node.cnt100][node.l]);

		for(int i=0; i<=cnt50; ++i)
			for(int j=0; j<=cnt100; ++j)
			{
				if((i == 0 && j == 0) || (i*50 + j*100 > w)) continue;

				Node newNode(node.cnt50-i, node.cnt100-j, 0);
				if(!node.l) newNode.cnt50 = node.cnt50 + i, newNode.cnt100 = node.cnt100 + j;
				newNode.l = 1 - node.l;

				int aux = (((ll)cntWays[node.cnt50][node.cnt100][node.l] * (ll)comb(cnt50, i))%MOD * (ll)comb(cnt100, j))%MOD;
				if(dist[newNode.cnt50][newNode.cnt100][newNode.l] == -1)
				{
					q.push(newNode);
					dist[newNode.cnt50][newNode.cnt100][newNode.l] = dist[node.cnt50][node.cnt100][node.l] + 1;
					cntWays[newNode.cnt50][newNode.cnt100][newNode.l] = aux;
				}
				else if(dist[newNode.cnt50][newNode.cnt100][newNode.l] == dist[node.cnt50][node.cnt100][node.l] + 1)
					cntWays[newNode.cnt50][newNode.cnt100][newNode.l] = (cntWays[newNode.cnt50][newNode.cnt100][newNode.l] + aux)%MOD;
			}
	}
	
	printf("%d\n%d\n", dist[0][0][0], cntWays[0][0][0]);

	return 0;
}
