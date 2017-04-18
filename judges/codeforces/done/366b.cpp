#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 100010
#define INF 1e9

int main()
{
	int n, k, mod[MAX];
		
	memset(mod, 0, sizeof(mod));
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
	{
		int v;
		scanf("%d", &v);
		mod[i%k] += v;
	}
	
	int sol = INF, start;
	for(int i=0; i<n; ++i) 
		if(mod[i] && sol > mod[i])
			start = i, sol = mod[i];
	printf("%d\n", start+1);

	return 0;
}
