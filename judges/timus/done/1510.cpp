#include<cstdio>
#include<map>
using namespace std;

#define INF (int) 1e9

int main()
{
  map<int, int> dic;
  map<int, int>::iterator it;
  int n, i;
  
  dic.clear();
  scanf("%d", &n);
  while(n--)
  {
    scanf("%d", &i);
    it = dic.find(i);
    if(it == dic.end())
      dic[i] = 1;
    else
      ++it->second;
  }
  
  int count = -INF;
  for(it=dic.begin(); it!=dic.end(); ++it)
      if(it->second > count)
      {
	count = it->second;
	i = it->first;
      }
  printf("%d\n", i);
    
  
  
  return 0;
}
