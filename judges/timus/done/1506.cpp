#include<cstdio>
#include<cmath>
using namespace std;

#define MAX 105

int main()
{
	int n, k, v[MAX], l, m[MAX][MAX], count;
	
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
		scanf("%d", &v[i]);
	
	l = ceil((double)n/(double)k);
	for(int i=n; i<l*k; ++i)
		v[i] = -1;
	
	count = 0;
	for(int j=0; j<k; ++j)
	{
		for(int i=0; i<l; ++i)
			m[i][j] = v[count++];
	}
			
	for(int i=0; i<l; ++i, puts(""))
		for(int j=0; j<k; ++j)
		{
			if(m[i][j] == -1)
				printf("    ");
			else
				printf("%4d", m[i][j]);
		}
	
	
	return 0;
}