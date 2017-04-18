#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 105

int main()
{
	int n, count, k, w;
	char s1[MAX], s2[MAX];
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &k, &w);
		getchar();
		gets(s1);
		
		count = k;
		while(--w)
		{
			gets(s2);
			//printf("s1= %s,  s2= %s\n", s1, s2);
			int i;
			for(i=0; i<k; ++i)
			{
				bool align = 1;
				for(int j=0; align && j<k-i; ++j)
					if(s2[j] != s1[i+j])
						align = 0;
				if(align)
					break;
			}
			
			count += i;
			//printf("count= %d\n", count);
			strncpy(s1, s2, k);
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}