//feito com grafo - fazer com union find

#include<stdio.h>
#include<list>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    unsigned n, cp, v1, v2, u, n1, n2;
    char c;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
	if(i != 0)
	    printf("\n");
	
	n1 = 0;
	n2 = 0;
	
	scanf("%d", &cp);
	
	//printf("cp = %d\n", cp);
	
	vector< list<unsigned> > l;
	l.resize(cp);
	vector<bool> m;
	m.resize(cp, 0);
	list<unsigned>::iterator it;
	
	queue<unsigned> f;
	
	while(1)
	{
	    scanf("%c", &c); //lê \n
	    
	    if(scanf("%c", &c) == EOF)
		break;
	    if(c == '\n')
		break;
		
	    scanf("%d %d", &v1, &v2);
	    v1--;
	    v2--;
	    
	    //printf("c = %c, v1 = %d, v2 = %d\n", c, v1, v2);
	    
	    if(c == 'c')
	    {
		l[v1].push_front(v2);
		l[v2].push_front(v1);
	    }
	    else //bfs
	    {
		m.assign(cp, 0);
		f.push(v1);
		m[v1] = 1;
		
		while(!f.empty())
		{
		    u = f.front();
		    f.pop();
		    
		    for(it = l[u].begin(); it != l[u].end(); it++)
		    {
			if(!m[*it])
			{
			    m[*it] = 1;
			    
			    f.push(*it);
			}
		    }
		}
		
		if(m[v2])
		    n1++;
		else
		    n2++;
	    }
	}
	
	printf("%d,%d\n", n1, n2);
    }
    
    return 0;
}