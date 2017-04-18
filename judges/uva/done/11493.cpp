#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX (int) 1e5 + 10

int main()
{
	int n, m, l, k, v[MAX], i, j, col, lin, countm, countn;
	
	while(scanf("%d %d %d %d", &n, &m, &l, &k) && n && m)
	{
		n *= 100; m *= 100;
		
		for(i=0; i<k; ++i)
		{
			scanf("%d", &v[i]);
			v[i] *= 100;
		}
		sort(v, v+k);
		
		if(n%l>0 && m%l>0)
		{
			puts("impossivel");
			continue;
		}
		
		if(n%l == 0)
		{
			countn = col = j = 0;
			for(i=k-1; i>=0; --i)
			{
				if(v[i] > m)
					continue;
				else if(v[i] == m)
				{
					++countn;
					col += l;
				}
				else
					for(; j<i; ++j)
					{
						if(v[i]+v[j] == m)
						{
							countn += 2;
							++j;
							col += l;
							break;
						}
						else if(v[i]+v[j] > m)
							break;
					}
				
				if(col == n)
					break;
			}
		}
		if(m%l == 0)
		{
			countm = lin = j = 0;
			for(i=k-1; i>=0; --i)
			{
				if(v[i] > n)
					continue;
				else if(v[i] == n)
				{
					++countm;
					lin += l;
				}
				else
					for(; j<i; ++j)
					{
						if(v[i]+v[j] == n)
						{
							countm += 2;
							++j;
							lin += l;
							break;
						}
						else if(v[i]+v[j] > n)
							break;
					}
				
				if(lin == m)
					break;
			}
		}
		
		if(col != n && lin != m)
			puts("impossivel");
		else if(col==n && lin==m)
			printf("%d\n", min(countm, countn));
		else if(col==n)
			printf("%d\n", countn);
		else
			printf("%d\n", countm);
	}
	
	return 0;
}