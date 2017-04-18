#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, t, x;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		int cntEven = 0;
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &x);
			if(x%2 == 0) ++cntEven;
		}
		
		bool can = 0;
		if(k == 0 && cntEven < n) can = 1;
		else if(k != 0 && cntEven >= k) can = 1;

		puts(can ? "YES" : "NO");
	}

	return 0;
}
