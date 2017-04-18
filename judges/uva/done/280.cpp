#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int main()
{
    int n, v1, v2, q, count;
    vector< list<int> > g;
    list<int>::iterator it;
    queue<int> f;
    bool marcado[110];
    g.resize(110);
    
    while(1)
    {
	scanf("%d", &n);
	if(!n)
	    break;
	
	list<int> l;
	l.clear();
	g.assign(110, l);
	
	while(1)
	{
	    scanf("%d", &v1);
	    if(!v1)
		break;
	    
	    while(1)
	    {
		scanf("%d", &v2);
		if(!v2)
		    break;
		
		g[v1].push_front(v2);
	    }
		
	}
	
	scanf("%d", &q);
	for(int i=0; i<q; ++i)
	{
	    memset(marcado, 0, (n+1)*sizeof(bool));
	    
	    scanf("%d", &v1);

	    f.push(v1);
	    //marcado[v1] = 1;
	    while(!f.empty())
	    {
		v1 = f.front();
		f.pop();
		
		for(it=g[v1].begin(); it!=g[v1].end(); ++it)
		{
		    if(!marcado[*it])
		    {
			marcado[*it] = 1;
			f.push(*it);
		    }
		}
	    }
	    
	    count = 0;
	    for(int i=1; i<=n; ++i)
		if(!marcado[i])
		    ++count;
	    
	    printf("%d", count);
	    for(int i=1; i<=n; ++i)
		if(!marcado[i])
		    printf(" %d", i);
	    puts("");
	}
    }
    return 0;
}