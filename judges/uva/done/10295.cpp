#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    int m, n, v, sum;
    string s;
    map<string, int> dic;
    map<string, int>::iterator it;
    
    dic.clear();
    
    scanf("%d %d", &m, &n);
    
    while(m--)
    {
	cin >> s;
	cin >> v;
	
	dic[s] = v;
    }
    
    while(n--)
    {
	sum = 0;
	
	while(1)
	{
	    cin >> s;
	    if(s == ".")
		break;
	    
	    it = dic.find(s);
	    if(it != dic.end())
		sum += it->second;
	}
	
	printf("%d\n", sum);
    }
    
    return 0;
}