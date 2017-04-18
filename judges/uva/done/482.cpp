#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;

typedef struct 
{
    int i;
    string s;
}No;

bool cmp(No a, No b)
{
    return a.i < b.i;
}

int main()
{
    int t;
    vector<No> v;
    char c;
    
    scanf("%d", &t);
    
    while(t--)
    {
	v.clear();
	
	while(1)
	{
	    No e;
	    scanf("%d", &(e.i));
	    v.push_back(e);
	    
	    scanf("%c", &c);
	    if(c == '\n')
		break;
	}
	
	for(int i=0; i<v.size(); ++i)
	    cin >> v[i].s;
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=0; i<v.size(); ++i)
	    cout << v[i].s << endl;
	
	if(t)
	    puts("");
    }
    
    return 0;
}