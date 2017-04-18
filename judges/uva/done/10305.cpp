#include<cstdio>
#include<vector>
#include<queue>
#include<list>
#include<cstring>
using namespace std;

int main()
{
    int n, m, v1, v2, gentrada[110];
    vector< list<int> > g;
    g.resize(110);
    list<int>::iterator it;
    bool marcado[110];
    
    while(1)
    {
	scanf("%d %d", &n, &m);
	if(!n && !m)
	    break;
	
	queue<int> f;
	memset(marcado, 0, (n+1)*sizeof(bool));
	memset(gentrada, 0, (n+1)*sizeof(int));
	list<int> l;
	l.clear();
	g.assign(110, l);
	
	
	while(m--)
	{
	    scanf("%d %d", &v1, &v2);
	    g[v1].push_front(v2);
	    
	    ++gentrada[v2];
	}
	
	for(int i=1; i<=n; ++i)
	    if(gentrada[i] == 0)
		f.push(i);

	while(!f.empty())
	{
	    v1 = f.front();
	    f.pop();
	    
	    for(it=g[v1].begin(); it !=g[v1].end(); ++it)
	    {
		--gentrada[*it];
		if(gentrada[*it] == 0)
		    f.push(*it);
	    }
	    
	    if(f.empty())
		printf("%d\n", v1);
	    else
		printf("%d ", v1);
	}
    }
    
    return 0;
}