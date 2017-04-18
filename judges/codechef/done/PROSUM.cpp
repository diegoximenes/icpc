#include<cstdio>
#include<set>
using namespace std;
 
typedef long long ll;
 
int main()
{
	multiset<int> tree;
	int t, n, x;
 
	scanf("%d", &t);
	while(t--)
	{
		tree.clear();
		scanf("%d", &n);
		for(int i=0; i<n; ++i) scanf("%d", &x), tree.insert(x);
		
		ll cnt = tree.size() - tree.count(0) - tree.count(1);
		ll cnt2 = tree.count(2);
 
		printf("%lld\n", cnt*(cnt-1)/2 - cnt2*(cnt2-1)/2);
	}
 
	return 0;
}