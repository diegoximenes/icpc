#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 100010

int main()
{
	int n, v[MAX], len, l;
	
	scanf("%d", &n);
	if(n == 1) len = l = 1;
	else len = l = 2;
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &v[i]);
		
		if(i >= 2)
		{
			if(v[i] != v[i-1] + v[i-2]) len = max(len, l), l = 2;
			else ++l;
		}
	}
	len = max(len, l);
	printf("%d\n", len);


	return 0;
}
