#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, x, y;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &x, &y);
		
		bool yes;
		
		if(x > 0)
		{
			int dy = -(x/2)*2, uy = (x/2)*2 + 2;
			if(x%2)
			{
				if(y >= dy && y <= uy) yes = 1;
				else if(y%2 == 0 && (y >= uy || y <= dy)) yes = 1;
				else yes = 0;
			}
			else
			{
				if(y%2 == 0 && (y >= uy || y <= dy)) yes = 1;
				else yes = 0;
			}
		}
		else if(x < 0)
		{
			int dy = -((-x+1)/2)*2, uy = ((-x+1)/2)*2;
			
			if(x%2)
			{
				if(y%2 == 0 && (y >= uy || y <= dy)) yes = 1;
				else yes = 0;
			}
			else
			{
				if(y >= dy && y<= uy) yes = 1;
				else if(y%2 == 0 && (y >= uy || y <= dy)) yes = 1;
				else yes = 0;
			}
		}
		else
		{
			if(y%2 == 0) yes = 1;
			else yes = 0;
		}

		puts(yes ? "YES" : "NO");
	}

	return 0;
}
