#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t, pd[30][300], w, sum, cap;
	vector<int> v;
	//char input[100];
	char c;
	
	scanf("%d", &t);
	//printf("t = %d\n", t);
	getchar();
	while(t--)
	{
		v.clear();
		
		while(1)
		{
			scanf("%d", &w);
			v.push_back(w);
			if(scanf("%c", &c) == EOF)
				break;
			if(c == '\n')
				break;
		}
		/*gets(input);
		printf("input = %s\n", input);
		while(sscanf(input, "%d", &w) == 1)
		{
			printf("w = %d\n", w);
			v.push_back(w);
		}*/
		
		/*printf("v =");
		for(int i=0; i<v.size(); ++i)
			printf("%d, ",v[i]);
		puts("");*/
		
		sum = 0;
		for(int i=0; i<v.size(); ++i)
			sum += v[i];
		
		/*printf("sum = %d", sum);
		puts("");*/
		
		if(sum%2 != 0)
		{
			printf("NO\n");
			continue;
		}
		
		cap = sum/2;
		
		//printf("cap = %d\n", cap);
		
		for(int i=0; i<=v.size(); ++i)
			pd[i][0] = 0;
		for(int i=0; i<=cap; ++i)
			pd[0][i] = 0;
		for(int i=1; i<=v.size(); ++i)
			for(int j=1; j<=cap; ++j)
			{
				pd[i][j] = pd[i-1][j];
				if(v[i-1] <= j)
					pd[i][j] = max(pd[i][j], pd[i-1][j-v[i-1]] + v[i-1]);
			}
		
		//printf("pd[v.size()][cap] = %d\n", pd[v.size()][cap]);
		if(pd[v.size()][cap] == cap)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}