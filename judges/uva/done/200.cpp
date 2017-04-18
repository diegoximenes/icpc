#include<cstdio>
#include<cstring>
#include<queue>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int gentrada[100], i;
    char s1[25], s2[25], c;
    vector< list<int> > g;
    list<int>::iterator it;
    bool marcado[100];
    queue<int> f;
    
    list<int> l;
    l.clear();
    g.assign(100, l);
    
    memset(gentrada, 0, 100*sizeof(int));
    memset(marcado, 0, 100*sizeof(bool));
    
    gets(s1);
    if(strcmp(s1, "#"))
    {
	for(i=0; i<strlen(s1); ++i)
	    marcado[(int) s1[i]] = 1;
	
	while(1)
	{
	    gets(s2);
	    if(!strcmp(s2, "#"))
		break;
	    
	    for(i=0; i<strlen(s2); ++i)
		marcado[(int) s2[i]] = 1;
	    
	    for(i=0; i<min(strlen(s1), strlen(s2)); ++i)
	    {
		if(s1[i] != s2[i])
		{
		    g[(int) s1[i]].push_front((int) s2[i]);
		    
		    ++gentrada[(int) s2[i]];
		    
		    break;
		}
	    }
	    
	    strcpy(s1, s2);
	}
	/*
	printf("marcado = ");
	for(int j=65; j<=90; ++j)
	    printf("%c(%d), ", (char)j, marcado[j]);
	puts("");
	
	printf("gentrada = ");
	for(int j=65; j<=90; ++j)
	    printf("%c(%d), ", (char)j, gentrada[j]);
	puts("");
	*/
	for(c='A'; c<='Z'; ++c)
	    if((marcado[(int) c]) && (gentrada[(int) c] == 0))
		f.push((int) c);
	    
	while(!f.empty())
	{
	    i = f.front();
	    f.pop();
	    
	    printf("%c", (char)i);
	    
	    for(it=g[i].begin(); it!=g[i].end(); ++it)
	    {
		--gentrada[*it];
		
		if(gentrada[*it] == 0)
		    f.push(*it);
	    }
	}		
    }
    puts("");
    return 0;
}