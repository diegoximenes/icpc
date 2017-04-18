#include<cstdio>
#include<cassert>
using namespace std;

#define MAX 1000+10

int pd[MAX][MAX];
int count1[MAX], count2[MAX];

void print(int i, int j)
{
  if(j<0 || i<0)
    return;
  if(i==0 && j==0)
    return;
  if(pd[i][j] == 0 )
  {
    printf("Impossible");
    return;
  }

  printf("%d", pd[i][j]);
  if(pd[i][j] == 2)
    print(i, j-1);
  else
    print(i-1, j);
    
}

int getCard(char *p1, char *p2, int n1, int n2, int red, int black)
{
  if(pd[n1][n2] != -1) return pd[n1][n2];
  if(count1[n1] + count2[n2]> n1+n2+1)
    return pd[n1][n2] = 0;
  if(red > black+1 || black > red+1) 
    return pd[n1][n2] = 0;
 
  if(n1 == 0 && n2 == 0)
    return pd[n1][n2] = 1;

  if(n1>0 && p1[0] == '0')
    if(!(red+1 > black+1) && getCard(p1+1, p2, n1-1, n2, red+1, black) !=0)
      return pd[n1][n2] = 1;
  if(n1>0 && p1[0] == '1')
    if(!(black+1 > red+1) && getCard(p1+1, p2, n1-1, n2, red, black+1) != 0)
      return pd[n1][n2] = 1;
  if(n2>0 && p2[0] == '0')
    if(!(red+1 > black+1) && getCard(p1, p2+1, n1, n2-1, red+1, black) != 0)
      return pd[n1][n2] = 2;
  if(n2>0 && p2[0] == '1')
    if(!(black+1 > red+1) && getCard(p1, p2+1, n1, n2-1, red, black+1) != 0)
      return pd[n1][n2] = 2;
  
  return pd[n1][n2]=0;
}

int main()
{
  int n;
  char p1[MAX], p2[MAX];
  char line[MAX];
  
  gets(line);
  sscanf(line, "%d", &n);
  gets(p1);
  gets(p2);
  
  for(int j=0; j<n; ++j)
  {
    count1[j] = count2[j] = 0;
    for(int i=0; i<j; ++i)
    {
      count1[j] += (p1[i] - '0');
      count2[j] += (p2[i] - '0');
    }
  }
    
  for(int i=0; i<=n; ++i)
    for(int j=0; j<=n; ++j)
      pd[i][j] = -1;
    
    getCard(p1, p2, n, n, 0, 0);
  
    print(n, n);
    puts("");
   
  return 0;
}