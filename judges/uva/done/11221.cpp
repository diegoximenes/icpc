#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	int t;
	char s[10000+100], g[105][105], s2[10000+100];
	
	scanf("%d\n", &t);
	for(int i=1; i<=t; ++i)
	{
		int n = 0;
		bool pal = 1;
		
		gets(s);
		for(int j=0; j<(int)strlen(s); ++j)
			if(isalpha(s[j]))
			{
				s2[n] = s[j];
				++n;
			}
		
		if(sqrt(n) - (int)sqrt(n) > 0.0)
			pal = 0;
		n = sqrt(n);
			
		int j = 0, k = 0;
		for(int m=0; m<(int)strlen(s); ++m)
			if(isalpha(s[m]))
			{
				g[j][k] = s[m];
				++j;
				if(j == n)
				{
					j = 0;
					++k;
				}
			}
		
		int m;
		for(j=0, m=0; j<n && pal; ++j)
			for(k=0; k<n && pal; ++k, ++m)
			{
				if(g[j][k] != s2[m])
					pal = 0;
				if(g[k][j] != s2[m])
					pal = 0;
			}
		for(j=n-1, m=0; j>=0 && pal; --j)
			for(k=n-1; k>=0 && pal; --k, ++m)
			{
				if(g[j][k] != s2[m])
					pal = 0;
				if(g[k][j] != s2[m])
					pal = 0;
			}			
				
		printf("Case #%d:\n", i);
		if(pal)
			printf("%d\n", n);
		else
			puts("No magic :(");
	}
	
	return 0;
}