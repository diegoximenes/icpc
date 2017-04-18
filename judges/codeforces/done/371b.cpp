#include<cstdio>
#include<queue>
#include<map>
using namespace std;

#define mp make_pair

int main()
{
	int a, b, sol = -1;
	map< pair<int, int>, int > dist;

	scanf("%d %d", &a, &b);

	queue< pair<int, int> > q;
	dist[mp(a, b)] = 0;
	q.push(mp(a, b));
	while(!q.empty())
	{
		a = q.front().first; b = q.front().second; q.pop();
		if(a == b)
		{
			sol = dist[mp(a, b)];
			break;
		}
		
		if(a%2 == 0 && dist.find(mp(a/2, b)) == dist.end()) dist[mp(a/2, b)] = dist[mp(a, b)] + 1, q.push(mp(a/2, b));
		if(b%2 == 0 && dist.find(mp(a, b/2)) == dist.end()) dist[mp(a, b/2)] = dist[mp(a, b)] + 1, q.push(mp(a, b/2));
		if(a%3 == 0 && dist.find(mp(a/3, b)) == dist.end()) dist[mp(a/3, b)] = dist[mp(a, b)] + 1, q.push(mp(a/3, b));
		if(b%3 == 0 && dist.find(mp(a, b/3)) == dist.end()) dist[mp(a, b/3)] = dist[mp(a, b)] + 1, q.push(mp(a, b/3));
		if(a%5 == 0 && dist.find(mp(a/5, b)) == dist.end()) dist[mp(a/5, b)] = dist[mp(a, b)] + 1, q.push(mp(a/5, b));
		if(b%5 == 0 && dist.find(mp(a, b/5)) == dist.end()) dist[mp(a, b/5)] = dist[mp(a, b)] + 1, q.push(mp(a, b/5));

	}
	printf("%d\n", sol);
	
	return 0;
}
