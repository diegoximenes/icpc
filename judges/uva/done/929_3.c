#include<stdio.h>
#include<limits.h>

#define MAX 1000

typedef struct
{
	int i, j, w;
}Vertex;

int g[MAX][MAX], dist[MAX][MAX], mark[MAX][MAX], ind[MAX][MAX];
Vertex heap[MAX*MAX];
int size;

void swap(int i, int j)
{
	Vertex aux;
	
	aux.i = heap[i].i;
	aux.j = heap[i].j;
	aux.w = heap[i].w;
			
	heap[i].i = heap[j].i;
	heap[i].j = heap[j].j;
	heap[i].w = heap[j].w;
			
	heap[j].i = aux.i;
	heap[j].j = aux.j;
	heap[j].w = aux.w;
}

void up(int i)
{
	int j = i/2;
	
	if(j>=1)
		if(heap[i].w < heap[j].w)
		{
			swap(i, j);
			
			up(j);
		}
}

void down(int i, int n)
{
	int j = 2*i;
	
	if(j <= n)
	{
		if(j < n)
			if(heap[j+1].w < heap[j].w)
				++j;
		if(heap[i].w > heap[j].w)
		{
			swap(i, j);
			
			down(j, n);
		}
	}
}

int insert(int i, int j, int w)
{
	++size;
	heap[size].i = i;
	heap[size].j = j;
	heap[size].w = w;
	up(size);
	
	return size;
}

Vertex min()
{
	Vertex v = heap[1];
	heap[1] = heap[size];
	--size;
	down(1, size);
	
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
				ind[i][j] = 0;
			}
		}
		
		size = 0;
		dist[0][0] = g[0][0];
		ind[0][0] = insert(0, 0, 0);
		
		while(size)
		{
			v = min();
			
			if((v.i == n-1) && (v.j == m-1))
				break;
			
			mark[v.i][v.j] = 1;
			
			for(k=0; k<4; ++k)
			{
				u.i = viz[k][0] + v.i;
				u.j = viz[k][1] + v.j;
				
				if((u.i>=0) && (u.i<n) && (u.j>=0) && (u.j<m))
					if((!mark[u.i][u.j]) && (dist[u.i][u.j] > dist[v.i][v.j] + g[u.i][u.j]))
					{
						dist[u.i][u.j] = dist[v.i][v.j] + g[u.i][u.j];
						
						if(ind[u.i][u.j] != 0)
						{
							heap[ind[u.i][u.j]].w = dist[u.i][u.j];
							
							up(ind[u.i][u.j]);
						}
						else
							ind[u.i][u.j] = insert(u.i, u.j, dist[u.i][u.j]);
					}
			}
			
		}
		
		printf("%d\n", dist[n-1][m-1]);
	}
	
	return 0;
}