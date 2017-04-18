#include<cstdio>
#include<cstring>
#include<list>
#include<vector>
#include<climits>
using namespace std;

#define MAX 30

typedef struct
{
	int v, w;
	char age;
}Vertex;

int main()
{
	int n, w, s1, s2, vmin, wmin, dist1[MAX], dist2[MAX];
	long long unsigned int mintotal, aux;
	bool marc[MAX];
	char age, dir, v1, v2;
	vector< list<Vertex> > g;
	list<Vertex> l;
	list<Vertex>::iterator it;
	Vertex v;
	
	l.clear();
	g.resize(MAX);
	
	while(1)
	{
		scanf("%d", &n);
		if(!n)
			break;
		getchar();
		
		g.assign(MAX, l);
		
		for(int i=0; i<n; ++i)
		{
			scanf("%c%*c%c%*c%c%*c%c %d", &age, &dir, &v1, &v2, &w);
			
			//printf("age= %c, dir= %c, v1= %c, v2= %c, w= %d\n", age, dir, v1, v2, w);
			getchar();
			v.v = v2 - 'A';
			v.w = w;
			v.age = age;
				
			g[v1-'A'].push_front(v);
			
			if(dir == 'B')
			{
				v.v = v1 - 'A';
				v.w = w;
				v.age = age;
				
				g[v2-'A'].push_front(v);
			}
		}
		
		scanf("%c%*c%c", &v1, &v2);
		//printf("v1= %c, v2=%c\n", v1, v2);
		getchar();
		s1 = v1 - 'A';
		s2 = v2 - 'A';
		
		//me
		for(int i=0; i<MAX; ++i)
			dist1[i] = INT_MAX;
		memset(marc, 0, MAX*sizeof(bool));
		dist1[s1] = 0;
		while(1)
		{
			vmin = -1;
			wmin = INT_MAX;
			for(int i=0; i<MAX; ++i)
			{
				if(!marc[i] && (dist1[i] < wmin))
				{
					wmin = dist1[i];
					vmin = i;
				}
			}
			
			if(vmin == -1)
				break;
			
			marc[vmin] = 1;
			
			for(it=g[vmin].begin(); it!=g[vmin].end(); ++it)
				if((!marc[it->v]) && (it->age == 'Y') && (dist1[it->v] > dist1[vmin] + it->w))
					dist1[it->v] = dist1[vmin] + it->w;
		}
		
		//prof
		for(int i=0; i<MAX; ++i)
			dist2[i] = INT_MAX;
		memset(marc, 0, MAX*sizeof(bool));
		dist2[s2] = 0;
		while(1)
		{
			vmin = -1;
			wmin = INT_MAX;
			for(int i=0; i<MAX; ++i)
			{
				if(!marc[i] && (dist2[i] < wmin))
				{
					wmin = dist2[i];
					vmin = i;
				}
			}
			
			if(vmin == -1)
				break;
			
			marc[vmin] = 1;
			
			for(it=g[vmin].begin(); it!=g[vmin].end(); ++it)
				if((!marc[it->v]) && (it->age == 'M') && (dist2[it->v] > dist2[vmin] + it->w))
					dist2[it->v] = dist2[vmin] + it->w;
		}
		
		//calc
		/*printf("dist1 = ");
		for(int i=0; i<MAX; ++i)
			printf("(%d)%d, ", i, dist1[i]);
		puts("\n");
		printf("dist2 = ");
		for(int i=0; i<MAX; ++i)
			printf("(%d)%d, ", i, dist2[i]);
		puts("\n");
		*/
		mintotal = INT_MAX;
		//vmin = -1;
		list<int> l2;
		l2.clear();
		list<int>::iterator it2;
		for(int i=0; i<MAX; ++i)
		{
			aux = dist1[i] + dist2[i];
			if(aux < mintotal)
			{
				l2.clear();
				l2.push_back(i);
				
				mintotal = aux;
			}
			else if((mintotal != INT_MAX) && (aux == mintotal))
				l2.push_back(i);
		}
		
		if(l2.empty())
			puts("You will never meet.");
		else
		{
			printf("%lld", mintotal);
			for(it2=l2.begin(); it2!=l2.end(); ++it2)
				printf(" %c", *it2 + 'A');
			puts("");
		}
	}

	return 0;
}