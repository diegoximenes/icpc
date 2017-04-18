#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 100010

int main()
{
	int n, k, v[MAX];

	scanf("%d %d", &n, &k);
	if(n-1 < k) puts("-1");
	else
	{
		k = n - k;
		for(int i=0; i<n; ++i) v[i] = i + 1;
		
		int i;
		if(k%2 == 0) i = 0;
		else i = 1, --k;
		
		for(; k > 0; k-=2, i+=2) swap(v[i], v[i+1]);
		
		printf("%d", v[0]);
		for(int j=1; j<n; ++j) printf(" %d", v[j]);
		puts("");
	}

	return 0;
}