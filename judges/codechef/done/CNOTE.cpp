#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, k, x, y;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d %d", &x, &y, &k, &n);
		
		x -= y;
		bool can = 0;
		if(x < 0) can = 1;
		
		for(int i=0; i<n; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if(x - a <= 0 && k >= b) can = 1;
		}
		
		puts(can ? "LuckyChef" : "UnluckyChef");
	}

	return 0;
}
