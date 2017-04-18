#include<cstdio>
#include<set>
#include<cstring>
using namespace std;

#define MAX 3010

int main()
{
	char s[10];
	int qnum, per, k, peri[MAX];
	set< pair<int, int> > heap;
	
	heap.clear();
	
	while(scanf("%s", s))
	{
		if(!strcmp(s, "#"))
			break;
		
		scanf("%d %d", &qnum, &per);
		
		heap.insert(make_pair(per, qnum));
		peri[qnum] = per;
	}
	
	scanf("%d", &k);
	
	while(k--)
	{
		per = (heap.begin())->first;
		qnum = (heap.begin())->second;
		
		heap.erase(heap.begin());
		
		printf("%d\n", qnum);
		
		heap.insert(make_pair(per+peri[qnum], qnum));
	}
	
	return 0;
}