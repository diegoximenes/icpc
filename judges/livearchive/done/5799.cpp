#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int v[3];

	while(scanf("%d %d %d", v, v+1, v+2) && (v[0] || v[1] || v[2]))
	{
		bool solved = 0;
		sort(v, v+3);

		if(v[0] == v[1] && v[1] == v[2]) //set
		{
			//puts("set");
			if(v[0] == 13) puts("*");
			else printf("%d %d %d\n", v[0]+1, v[0]+1, v[0]+1);
		}
		else if(v[0] == v[1] || v[0] == v[2] || v[1] == v[2]) //pair
		{
			//puts("pair");
			if(v[0] == v[1])
			{
				for(int i=v[2]+1; i<=13 && !solved; ++i)
					if(i != v[0] && i != v[1])
					{
						v[2] = i; sort(v, v+3);
						printf("%d %d %d\n", v[0], v[1], v[2]);
						solved = 1;
					}
				if(!solved && v[0] != 13)
				{ 
					v[0] = v[1] = v[0] + 1; v[2] = 1;
					sort(v, v+3);
					printf("%d %d %d\n", v[0], v[1], v[2]);
				}
				else if(!solved) puts("1 1 1");
			}
			else if(v[0] == v[2])
			{
				for(int i=v[1]+1; i<=13 && !solved; ++i)
					if(i != v[0] && i != v[2])
					{
						v[1] = i; sort(v, v+3);
						printf("%d %d %d\n", v[0], v[1], v[2]);
						solved = 1; 
					}
				if(!solved && v[0] != 13)
				{ 
					v[0] = v[2] = v[0] + 1; v[1] = 1;
					sort(v, v+3);
					printf("%d %d %d\n", v[0], v[1], v[2]);
				}
				else if(!solved) puts("1 1 1");
			}
			else if(v[1] == v[2])
			{
				for(int i=v[0]+1; i<=13 && !solved; ++i)
					if(i != v[1] && i != v[2])
					{
						v[0] = i; sort(v, v+3);
						printf("%d %d %d\n", v[0], v[1], v[2]);
						solved = 1;
					}
				if(!solved && v[1] != 13)
				{ 
					v[1] = v[2] = v[1] + 1; v[0] = 1;
					sort(v, v+3);
					printf("%d %d %d\n", v[0], v[1], v[2]);
				}
				else if(!solved) puts("1 1 1");
			}
		}
		else
			puts("1 1 2");
	}
		
	return 0;
}
