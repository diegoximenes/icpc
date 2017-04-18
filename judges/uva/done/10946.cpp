#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct 
{
    int i, j;
    char c;
}Cel;

typedef struct 
{
    int count;
    char c;
}Item;

bool cmp(Item a, Item b)
{ 
    if(a.count > b.count)
	return 1;
    else if(a.count < b.count)
	return 0;
    else
	return a.c < b.c;
}

int main()
{
    int x, y, i, j, marcado[55][55], count, p, k, l;
    char m[55][55];
    queue<Cel> f;
    vector<Item> v;
    Cel cel, cel2;
    Item item;
    
    for(p=1; ; ++p)
    {
	scanf("%d %d", &x, &y);
	getchar();
	if(!x && !y)
	    break;
	
	v.clear();
	
	for(i=0; i<x; ++i)
	{
	    for(j=0; j<y; ++j)
	    {
		scanf("%c", &m[i][j]);
		if(m[i][j] == '.')
		    marcado[i][j] = 1;
		else
		    marcado[i][j] = 0;
	    }
	    getchar();
	}
	
	for(i=0; i<x; ++i)
	{
	    for(j=0; j<y; ++j)
	    {
		if(!marcado[i][j])
		{
		    cel.i = i;
		    cel.j = j;
		    cel.c = m[i][j];
		    
		    f.push(cel);
		    marcado[i][j] = 1;
		    count = 1;
		    
		    while(!f.empty())
		    {
			cel = f.front();
			f.pop();
			
			k = cel.i - 1;
			l = cel.j;
			if((k>=0) && (k<x) && (l>=0) && (l<y) && (!marcado[k][l]) && (m[k][l] == cel.c))
			{
			    cel2.i = k;
			    cel2.j = l;
			    cel2.c = cel.c;
			    marcado[k][l] = 1;
				    
			    f.push(cel2);
				
			    ++count;
			}
			k = cel.i + 1;
			l = cel.j;
			if((k>=0) && (k<x) && (l>=0) && (l<y) && (!marcado[k][l]) && (m[k][l] == cel.c))
			{
			    cel2.i = k;
			    cel2.j = l;
			    cel2.c = cel.c;
			    marcado[k][l] = 1;
				    
			    f.push(cel2);
				
			    ++count;
			}
			k = cel.i;
			l = cel.j - 1;
			if((k>=0) && (k<x) && (l>=0) && (l<y) && (!marcado[k][l]) && (m[k][l] == cel.c))
			{
			    cel2.i = k;
			    cel2.j = l;
			    cel2.c = cel.c;
			    marcado[k][l] = 1;
				    
			    f.push(cel2);
				
			    ++count;
			}
			k = cel.i;
			l = cel.j+1;
			if((k>=0) && (k<x) && (l>=0) && (l<y) && (!marcado[k][l]) && (m[k][l] == cel.c))
			{
			    cel2.i = k;
			    cel2.j = l;
			    cel2.c = cel.c;
			    marcado[k][l] = 1;
				    
			    f.push(cel2);
				
			    ++count;
			}
			/*for(k=cel.i - 1; k<=cel.i + 1; ++k)
			    for(l=cel.j - 1; l<=cel.j + 1; ++l)
				if((k>=0) && (k<x) && (l>=0) && (l<y) && (!marcado[k][l]) && (m[k][l] == cel.c))
				{
				    cel2.i = k;
				    cel2.j = l;
				    cel2.c = cel.c;
				    marcado[k][l] = 1;
				    
				    f.push(cel2);
				    
				    ++count;
				}
				*/
		    }
		    
		    item.count = count;
		    item.c = cel.c;
		    
		    v.push_back(item);
		}
	    }
	}
	
	sort(v.begin(), v.end(), cmp);
	
	printf("Problem %d:\n", p);
	for(k=0; k<v.size(); ++k)
	    printf("%c %d\n", v[k].c, v[k].count);
	    
    }
    
    return 0;
}