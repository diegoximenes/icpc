#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, h, sh, sum = 0, s;
	
	scanf("%d %d %d", &n, &m, &h);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d", &s);
		if(i == h) sh = s;
		sum += s; 
	}

	if(n > sum) puts("-1");
	else if(sh < 2) puts("0");
	else 
	{
		n--; sh--; sum--;
		double p = 1.0;
		for(int i=0; i<sh; ++i) p *= (double)(sum - n - i)/(double)(sum - i);

		printf("%.7lf\n", 1.0 - p);
	}

	return 0;
}
