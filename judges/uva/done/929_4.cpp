#include<cstdio>
#include<climits>
#include<queue>
using namespace std;

#define MAX 1000

typedef struct
{
	int i, j, w;
}Vertex;

int g[MAX][MAX], dist[MAX][MAX], mark[MAX][MAX];
int currentheap;
queue< Vertex > heap[10];

void enqueue(int i, int j, int w)
{
	Vertex v;
	v.i = i;
	v.j = j;
	v.w = w;
	heap[w%10].push(v);
}

Vertex dequeue()
{
	Vertex v;
	int startheap = currentheap;
	
	while(heap[currentheap].empty())
	{
		currentheap = (currentheap+1)%10;
		if(currentheap == startheap)
		{
			v.i = v.j = v.w = -1;
			return v;
		}
	}
	
	v = heap[currentheap].front();
	heap[currentheap].pop();
	
	return v;
}

int main()
{
	int i, j, t, n, m, k;
	char line[2500];
	int viz[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
	Vertex v, u;
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d", &n, &m);
		getchar();
		
		for(i=0; i<n; ++i)
		{
			gets(line);
			k = 0; 
			for(j=0; j<m; ++j)
			{
				g[i][j] = line[k] - '0';
				k += 2;
				
				dist[i][j] = INT_MAX/3;
				mark[i][j] = 0;
			}
		}
		
		for(i=0; i<10; ++i)
			while(!heap[i].empty())
				heap[i].pop();
		
		dist[0][0] = g[0][0];
		mark[0][0] = 1;
		currentheap = dist[0][0];
		enqueue(0, 0, dist[0][0]);
		
		while(1)
		{
			v = dequeue();
			
			if((v.i == -1) && (v.j == -1) && (v.w == -1))
				break;
			
			if((v.i == n-1) && (v.j == m-1))
				break;
			
			for(k=0; k<4; ++k)
			{
				u.i = viz[k][0] + v.i;
				u.j = viz[k][1] + v.j;
				
				if((u.i>=0) && (u.i<n) && (u.j>=0) && (u.j<m))
					if(!mark[u.i][u.j])
					{
						dist[u.i][u.j] = dist[v.i][v.j] + g[u.i][u.j];
						mark[u.i][u.j] = 1;
						
						
						enqueue(u.i, u.j, dist[u.i][u.j]);
					}
			}
		}
		
		printf("%d\n", dist[n-1][m-1]);
	}
	
	return 0;
}