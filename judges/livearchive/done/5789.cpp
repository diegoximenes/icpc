#include<cstdio>
using namespace std;

#define MAX 100010

int main()
{
	int n, m, r, l, right[MAX], left[MAX];

	while(scanf("%d %d", &n, &m) && n)
	{
		for(int i=0; i<n; ++i)
		{
			left[i] = i-1;
			right[i] = i+1;
		}
		right[n-1] = -1;

		while(m--)
		{
			scanf("%d %d", &l, &r);
			--l; --r;
			
			if(left[l] >= 0) right[left[l]] = right[r];
			if(right[r] < n) left[right[r]] = left[l];

			if(left[l] == -1) printf("* ");
			else printf("%d ", left[l] + 1);
			if(right[r] == -1) printf("*\n");
			else printf("%d\n", right[r] + 1);
		}
		puts("-");
	}
	
	return 0;
}
