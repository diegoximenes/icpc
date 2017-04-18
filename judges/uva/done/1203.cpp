#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 3010

int main()
{
	char s[20];
	int qnum, per, k, peri[MAX];
	priority_queue< pair<int, int> > heap;
		
	while(scanf("%s", s))
	{
		if(!strcmp(s, "#"))
			break;
		
		scanf("%d %d", &qnum, &per);
		
		heap.push(make_pair(-per, -qnum));
		peri[qnum] = per;
	}
	
	scanf("%d", &k);
	
	while(k--)
	{
		per = -heap.top().first;
		qnum = -heap.top().second;
		
		heap.pop();
		
		printf("%d\n", qnum);
		
		heap.push(make_pair(-(per+peri[qnum]), -qnum));
	}
	
	return 0;
}