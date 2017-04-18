#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;

#define MAX 1100

int main()
{
   int k, n, nv, review[MAX], v, paper[MAX][10];
   bool prob[MAX], revpap[MAX];
   string s;
   map<string, int> dic;
   map<int, int> dic2;
   
   while(1)
   {
	 scanf("%d %d", &k, &n);
	 if(!n && !k)
	    break;
	 
	 dic.clear();
	 dic2.clear();
	 
	 nv = 0;
	 memset(review, 0, (n+1)*sizeof(int));
	 memset(prob, 0, (n+1)*sizeof(bool));
	 for(int i=1; i<=n; ++i)
	 {
	    cin >> s;
	    
	    if(dic.find(s) == dic.end())
	    {
		  dic[s] = nv;
		  dic2[i] = nv;
		  ++nv;
	    }
	    else
		  dic2[i] = dic[s];
	    
	    for(int j=0; j<k; ++j)
		  scanf("%d", &paper[i][j]);
	 }
	 
	 for(int i=1; i<=n; ++i)
	 {
	    memset(revpap, 0, (n+1)*sizeof(bool));
	    for(int j=0; j<k; ++j)
	    {
		  v = paper[i][j];
		  
		  if(revpap[v] == 1) //reviu mesmo paper
			prob[v] = 1;
		  if(dic2[v] == dic2[i]) //mesma univ
			prob[v] = 1;
		  
		  revpap[v] = 1;
		  ++review[v];
	    }
	 }
	 
	 for(int i=1; i<=n; ++i) //revisao do paper nao foi k
	    if(review[i] != k)
		  prob[i] = 1;
	   
	 int count = 0;
	 for(int i=1; i<=n; ++i)
	    if(prob[i])
		  ++count;
	 
	 if(count == 1)
	    puts("1 PROBLEM FOUND");
	 else if(count == 0)
	    puts("NO PROBLEMS FOUND");
	 else
	    printf("%d PROBLEMS FOUND\n", count);
   }
   
   return 0;
}