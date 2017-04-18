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

#define ll long long
#define pb push_back
#define mp make_pair
#define INF 1e9


int main()
{
	int a, b, sol = 0, rest = 0;

	scanf("%d %d", &a, &b);
	while(a)
	{
		//int aux = a;
		sol += a;
		rest += a%b;
		a = a/b;
		
		//printf("aux= %d, a= %d, rest= %d\n", aux, a, rest);
		if(a == 0)
		{
			a = rest/b, rest = rest%b;
			if(a + rest < b)
			{
				sol += a;
				break;
			}
		}
	}
	printf("%d\n", sol);

	return 0;
}
