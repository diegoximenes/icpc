#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int cmp(const void *a, const void *b)
{
    char *c1 = (char *)a;
    char *c2 = (char *)b;
    //printf("*c1 = %c, *c2 = %c, *c1-*c2 = %d \n", *c1, *c2, *c1-*c2);
    return *c1 - *c2;
}

bool cmp2(string s1, string s2)
{
    return (s1 < s2);
}

int main()
{
    char c[10];
    map< string, vector<string> > m;
    m.clear();
    string s_ord, s;
    
    while(1)
    {
	scanf("%s", c);
	
	if(!strcmp(c, "XXXXXX"))
	    break;
	
	s = c;
	
	//cout << "s = " << s << ", ";
	
	qsort(c, strlen(c), sizeof(char), cmp);
	
	s_ord = c;
	
	//printf("c = %s", c);
	//cout << ", s_ord = " << s_ord << endl;
	
	if(m.find(s_ord) == m.end())
	{
	    vector<string> v;
	    v.clear();
	    v.push_back(s);
	    
	    m[s_ord] = v;
	}
	else
	    m[s_ord].push_back(s);
    }
    
    while(1)
    {
	scanf("%s", c);
	
	if(!strcmp(c, "XXXXXX"))
	    break;
	
	qsort(c, strlen(c), sizeof(char), cmp);
	
	s_ord = c;
	
	if(m.find(s_ord) == m.end())
	    printf("NOT A VALID WORD\n******\n");
	else
	{
	    vector<string>::iterator it;
	    
	    sort(m[s_ord].begin(), m[s_ord].end(), cmp2);
	    
	    for(it = m[s_ord].begin(); it < m[s_ord].end(); ++it)
		cout << *it << endl;
	    printf("******\n");
	}
    }
    
    return 0;
}