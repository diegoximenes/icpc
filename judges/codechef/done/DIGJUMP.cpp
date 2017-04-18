#include<cstdio>
#include<cstring>
#include<list>
#include<vector>
#include<queue>
using namespace std;

#define pb push_back
#define MAX 100005
#define INF 1e9

int n, dist[MAX];
char s[MAX];
vector<int> digit[10];
bool foundDigit[10];

int main()
{
	scanf(" %s ", s);
	n = strlen(s);
	
	for(int i=0; i<n; ++i)
	{
		digit[s[i] - '0'].pb(i);
		dist[i] = INF;
	}
	
	memset(foundDigit, 0, sizeof(foundDigit));
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
	
		//printf("u= %d, dist[u] = %d\n", u, dist[u]);
	
		if(u == n-1)
		{
			printf("%d\n", dist[u]);
			return 0;
		}
			
		if(u+1 < n && dist[u + 1] == INF) q.push(u + 1), dist[u + 1] = dist[u] + 1;
		if(u-1 >= 0 && dist[u - 1] == INF) q.push(u - 1), dist[u - 1] = dist[u] + 1;
		
		if(!foundDigit[s[u] - '0'])
			for(int i=0; i<(int)digit[s[u] - '0'].size(); ++i)
				if(dist[digit[s[u] - '0'][i]] == INF)
				{
					q.push(digit[s[u] - '0'][i]);
					dist[digit[s[u] - '0'][i]] = dist[u] + 1;
				}
	
		foundDigit[s[u] - '0'] = 1;
	}
	
	return 0;
}
