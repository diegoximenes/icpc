#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

#define MAX 10000+100

int main()
{
	int t, m, n;
	map<char, int> dic;
	char s[MAX];
	
	scanf("%d", &t);
	while(t--)
	{
		dic.clear();
		scanf("%d\n", &n);
		while(n--)
		{
			char c; int v;
			scanf("%c %d\n", &c, &v);
			dic[c] = v;
		}
		scanf("%d\n", &m);
		
		double v = 0;
		while(m--)
		{
			gets(s);
			for(int i=0; i<(int)strlen(s); ++i)
				if(dic.find(s[i]) != dic.end())
					v += (double)dic[s[i]]/100.0;
		}
		printf("%.2lf$\n", v);
	}
	
	return 0;
}
