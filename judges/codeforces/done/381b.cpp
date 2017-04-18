#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;

#define MAX 100010

bool mark[5*MAX];

int main()
{
	int n, v[MAX];

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	sort(v, v+n);
	
	deque<int> dq;
	dq.push_back(v[n-1]);
	for(int i=n-2; i>=0; --i)
	{
		if(v[i] < dq.back()) dq.push_back(v[i]);
		else if(v[i] < dq.front()) dq.push_front(v[i]);
	}
	
	printf("%d\n%d", (int)dq.size(), *dq.begin());
	for(deque<int>::iterator it = dq.begin() + 1; it != dq.end(); ++it)
		printf(" %d", *it);
	puts("");
	
	return 0;
}
