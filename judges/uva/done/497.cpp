#include<cstdio>
#include<cstring>
#include<cctype>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	int t, maior, pd[500000], prev[500000], inmaior, num;
	vector<int> v;
	char input[1000];
	
	scanf("%d", &t);
	getchar();
	getchar();
	
	while(t--)
	{
		v.clear();
		v.push_back(0);
		stack<int> p;
		
		while(gets(input) != NULL)
		{
			if (strlen(input) == 0)
				break;
			else
			{
				sscanf(input, "%d", &num);
				v.push_back(num);
			}
			
			//if(scanf("%c", &c) == EOF)
			//	break;
			
			//printf("c = %c\n", c);
			//break;
			
			/*if(isdigit(c))
			{
				v.push_back(c - '0');
				getchar();
			}
			else
				break;*/
		}
		
		for(int i=1; i<=v.size()-1; ++i)
		{
			pd[i] = 1;
			prev[i] = i;
			
			for(int j=i-1; j>=1; --j)
			{
				if(v[j] < v[i])
				{
					if(pd[j]+1 > pd[i])
					{
						prev[i] = j;
						pd[i] = pd[j] + 1;
					}	
				}
			}
		}
		
		/*printf("v= ");
		for(int i=1; i<=v.size()-1; ++i)
			printf("%d, ", v[i]);
		printf("\n");*/
		
		maior = inmaior = 0;
		for(int i=1; i<=v.size()-1; ++i)
		{
			if(pd[i] > maior)
			{
				inmaior = i;
				maior = pd[i];
			}
		}
		printf("Max hits: %d\n", maior);
		while(1)
		{
			p.push(v[inmaior]);
			if(prev[inmaior] == inmaior)
				break;
			else
				inmaior = prev[inmaior];
		}
		
		if(maior != 0)
		{
			while(!p.empty())
			{
				printf("%d\n", p.top());
				p.pop();
			}
		}
		
		if(t != 0)
			puts("");
	}
	
	return 0;
}