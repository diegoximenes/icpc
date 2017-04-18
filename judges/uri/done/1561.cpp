#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9

int main()
{
	int h, m;

	while(scanf("%d:%d", &h, &m) == 2)
	{
		puts(" ____________________________________________");
		puts("|                                            |");
		puts("|    ____________________________________    |_");
		puts("|   |                                    |   |_)");
		puts("|   |   8         4         2         1  |   |");
		puts("|   |                                    |   |");
		printf("|   |   ");

		for(int i=3; i>=0; --i)
		{
			if((1 << i) & h) printf("o");
			else printf(" ");

			if(i > 0) printf("         ");
			else puts("  |   |");
		}

		puts("|   |                                    |   |");
		puts("|   |                                    |   |");
		
		printf("|   |   ");
		for(int i=5; i>=0; --i)
		{
			if((1 << i) & m) printf("o");
			else printf(" ");

			if(i > 0) printf("     ");
			else puts("  |   |");
		}
		
		puts("|   |                                    |   |");
		puts("|   |   32    16    8     4     2     1  |   |_");
		puts("|   |____________________________________|   |_)");
		puts("|                                            |");
		puts("|____________________________________________|");

		puts("");
	}

	return 0;
}
