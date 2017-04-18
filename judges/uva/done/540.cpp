#include<cstdio>
#include<map>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    int t, n, i, e, j, k;
    map<int, int> m;
    char s[10];
    bool flag;
    vector< queue<int> > v;
    
    for(k=0; ; ++k)
    {
	scanf("%d", &t);
	//printf("t = %d\n", t);
	if(!t)
	    break;
	
	printf("Scenario #%d\n", k+1);
	
	v.clear();
	m.clear();
	
	for(i=0; i<t; ++i)
	{
	    scanf("%d", &n);
	    
	    //printf("n = %d\n", n);
	    
	    while(n--)
	    {
		scanf("%d", &e);
		m[e] = i;
		
		//printf("e = %d, m[e] = %d\n", e, m[e]);
	    }
	}
	    
	while(1)
	{
	    scanf("%s", s);
		
	    if(!strcmp(s, "STOP"))
		break;
		
	    if(!strcmp(s, "ENQUEUE"))
	    {
		scanf("%d", &e);
		
		flag = 0;
		for(j=0; j < v.size(); ++j)
		{
		    if((!v[j].empty()) && (m[v[j].front()] == m[e]))
		    {
			flag = 1;
			
			v[j].push(e);
			//printf("m[v[j].front] = %d, m[e] = %d, e = %d\n", m[v[j].front()], m[e], e);
			break;
		    }
		}
		    
		if(!flag)
		{
		    queue<int> q;
		    q.push(e);
			
		    v.push_back(q);
		}
	    }
	    else
	    {
		for(j=0; j < v.size(); ++j)
		{
		    if(!v[j].empty())
		    {
			printf("%d\n", v[j].front());
			v[j].pop();
			break;
		    }
		}
	    }
	}
	
	puts("");
    }
    
    return 0;
}