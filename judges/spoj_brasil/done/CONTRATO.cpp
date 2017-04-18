#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int iaux;
	char s[150], d;
	
	while(scanf("%c", &d) && (d != '0'))
	{
		iaux = -1;
		
		scanf("%s", s);
		for(int i=0; i<(int)strlen(s); ++i)
		{
			if(s[i] == d)
				continue;
			else if(s[i] != '0')
			{
				iaux = i;
				break;
			}
		}
		if(iaux == -1)
			puts("0");
		else
		{
			for(int i=iaux; i<(int)strlen(s); ++i)
			{
				if(s[i] == d)
					continue;
				printf("%c", s[i]);
			}
			puts("");
		}
		getchar();
	}
	
	return 0;
}
