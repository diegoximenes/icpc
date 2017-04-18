#include<cstdio>
#include<cstring>
#include<climits>
#include<stack>
#include<iostream>
#include<map>
#include<set>
using namespace std;

#define MAX 110

typedef struct
{
	char s[15];
	int w;
}Edge;

int main()
{
	int w, nv, pai[MAX], v1, v2;
	long long unsigned dist[MAX];
	bool marc[MAX];
	Edge g[MAX][MAX];
	char cid1[25], cid2[25], rot[15], input[200];
	string str1, str2;
	map<string, int> dic;
	map<int, string> dic2;
	
	for(int i=0; i<MAX; ++i)
		for(int j=0; j<MAX; ++j)
			g[i][j].w = INT_MAX;
	
	nv = 0;
	while(1)
	{
		gets(input);
		
		if ( strlen(input) == 0)
			break;
		
		sscanf(input, "%[^,],%[^,],%[^,],%d%*c", cid1, cid2, rot, &w);
		
		str1 = cid1;
		if(dic.find(str1) ==  dic.end())
		{
			dic[str1] = nv;
			dic2[nv] = str1;
			++nv;
		}
		str2 = cid2;
		if(dic.find(str2) ==  dic.end())
		{
			dic[str2] = nv;
			dic2[nv] = str2;
			++nv;
		}
		
		v1 = dic[str1];
		v2 = dic[str2]; 
		
		//cout << "str1 = " << str1 << ", str2= " << str2 << ", v1= " << v1 << ", v2= " << v2 << ", w= " << w << endl;
		
		if((g[v1][v2].w == INT_MAX) || (g[v1][v2].w > w))
		{
			g[v1][v2].w = w;
			strcpy(g[v1][v2].s, rot);
			
			g[v2][v1].w = w;
			strcpy(g[v2][v1].s, rot);
		}
	}
	
	while(1)
	{
		if ( gets(input) == NULL)
			return 0;
		
		if ( strlen(input) == 0)
			break;
		
		sscanf(input, "%[^,],%[^,]%*c", cid1, cid2);
		
		str1 = cid1;
		str2 = cid2;
		v1 = dic[str1];
		v2 = dic[str2];
		
		//cout << "str1 = " << str1 << ", str2= " << str2 << ", v1= " << v1 << ", v2= " << v2 << endl;
		
		memset(marc, 0, nv*sizeof(bool));
		for(int i=0; i<nv; ++i)
		{
			dist[i] = INT_MAX;
			pai[i] = -1;
		}
		
		dist[v1] = 0;
		
		set< pair<int, int> > heap;
		heap.clear();
		heap.insert(make_pair(0, v1));
		int vmin;
		while(1)
		{
			if(heap.empty())
				break;
			
			vmin = (heap.begin())->second;
			
			if(vmin == v2)
				break;
			
			marc[vmin] = 1;
			
			heap.erase(heap.begin());
			
			for(int u=0; u<nv; ++u)
			{
				//printf("g[vmin][u].w = %d\n", g[vmin][u].w);
				if(!marc[u] && (dist[vmin] + g[vmin][u].w < dist[u]))
				{
					heap.erase(make_pair(dist[u], u));
					dist[u] = dist[vmin] + g[vmin][u].w;
					pai[u] = vmin;
					heap.insert(make_pair(dist[u], u));
				}
			}
		}
		
		int v = v2;
		
		/*
		printf("dist= ");
		for(int i=0; i<nv; ++i)
			printf("%d, ", dist[i]);
		puts("");
		
		printf("pai= ");
		for(int i=0; i<nv; ++i)
			printf("%d, ", pai[i]);
		puts("");
		*/
		stack<int> p;
		while(v != v1)
		{
			p.push(v);
			//cout << "From = " << dic2[v] << "To = " << dic2[pai[v]];
			//printf(", Route = %s, Miles = %d\n", g[v][pai[v]].s, g[v][pai[v]].w);
			
			
			v = pai[v];
		}
		
		printf("\n\nFrom                 To                   Route      Miles\n-------------------- -------------------- ---------- -----\n");
		
		while(!p.empty())
		{
			int v = p.top();
			p.pop();
			
			printf("%-20s %-20s %-10s %5d\n", (dic2[pai[v]]).c_str(), (dic2[v]).c_str(), g[v][pai[v]].s, g[v][pai[v]].w);
// 			cout << "From = " << dic2[pai[v]]  << "To = " << dic2[v];
// 			printf(", Route = %s, Miles = %d\n", g[v][pai[v]].s, g[v][pai[v]].w);
		}
		printf("%58s\n", "-----");
		printf("%42sTotal%6s%5lld\n", "", "", dist[v2]);
	}
}