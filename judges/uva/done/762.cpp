#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<stack>
using namespace std;

int main()
{
	int n, v1, v2, nv;
	string s1, s2;
	map<string, int> dic;
	map<int, string> dic2;
	list<int>::iterator it;
	list<int> l;
	bool flag, flag2;
	
	flag2 = 0;
	while(1)
	{	
		if(scanf("%d", &n) == EOF)
			break;
		
		if(!flag2)
			flag2 = 1;
		else
			puts("");
		
		dic.clear();
		dic2.clear();
		vector< list<int> > g;
		vector<bool> marc;
		vector<int> dad;
		queue<int> f;
		g.clear();

		nv = 0;
		for(int i=0; i<n; ++i)
		{
			cin >> s1;
			cin >> s2;
			
			if(dic.find(s1) != dic.end())
				v1 = dic[s1];
			else
			{
				dic[s1] = nv;
				dic2[nv] = s1;
				v1 = nv;
				++nv;
				
				g.push_back(l);
			}
			
			if(dic.find(s2) != dic.end())
				v2 = dic[s2];
			else
			{
				dic[s2] = nv;
				dic2[nv] = s2;
				v2 = nv;
				++nv;
				
				g.push_back(l);
			}
			
			//printf("v1=%d, v2=%d,  g.size() = %d\n", v1, v2, g.size());
			
			g[v1].push_front(v2);
			g[v2].push_front(v1);
		}
		
		cin >> s1;
		cin >> s2;
		
		if(n!=0)
		{
			if((dic.find(s1) == dic.end()) || (dic.find(s2) == dic.end()))
				puts("No route");
			else if(s1 == s2)
				cout << s1 << " " << s1 << endl;
			else
			{
				v1 = dic[s1];
				v2 = dic[s2];
				
				marc.assign(nv, 0);
				dad.assign(nv, 0);
				
				marc[v1] = 1;
				dad[v1] = v1;
				f.push(v1);
				
				flag = 0;
				
				while(!f.empty() && !flag)
				{
					v1 = f.front();
					f.pop();
					
					for(it=g[v1].begin(); it!=g[v1].end(); ++it)
					{
						if(!marc[*it])
						{	
							marc[*it] = 1;
							dad[*it] = v1;
							
							if(*it == v2)
							{
								flag = 1;
								break;
							}
							
							f.push(*it);
						}
					}
				}
				if(!flag)
					puts("No route");
				else
				{
					stack<int> p;
					while(1)
					{
						p.push(v2);
						
						if(dad[v2] == v2)
							break;
						
						v2 = dad[v2];
					}
					
					v1 = p.top();
					p.pop();
					s1 = dic2[v1];
					while(!p.empty())
					{	
						v2 = p.top();
						p.pop();
						s2 = dic2[v2];
						
						cout << s1 << " " << s2 << endl;
						
						s1 = s2;
					}
				}
			}
		}
		else
			puts("No route");
	}
	
	return 0;
}