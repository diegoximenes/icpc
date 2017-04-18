#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 3010

int main()
{
	int n, m, v[MAX];

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i) scanf("%d", &v[i]);
	sort(v, v+m);
	
	bool can = 1;
	if(v[0] == 1 || v[m-1] == n) can = 0;
	for(int i=0; can && i<m-2; ++i)
		if(v[i] == v[i+1]-1 && v[i+1] == v[i+2]-1)
			can = 0;

	if(can) puts("YES");
	else puts("NO");

	return 0;
}

