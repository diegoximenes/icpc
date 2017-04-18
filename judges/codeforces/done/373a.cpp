#include<cstdio>
#include<algorithm>
using namespace std;

int coun[11];

int main()
{
	int k, maxc = 0;
	
	scanf("%d\n", &k);
	for(int i=0; i<4; ++i, scanf("%*c"))
		for(int j=0; j<4; ++j)
		{
			char c;
			scanf("%c", &c);
			if(c != '.')
			{ 
				coun[c-'0']++;
				maxc = max(maxc, coun[c-'0']);
			}
		}
	if(2*k >= maxc) puts("YES");
	else puts("NO");
	
	return 0;
}
