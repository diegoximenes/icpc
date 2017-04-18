#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, e;
    vector<int> v;
    
    while(1)
    {
	scanf("%d", &n);
	if(n == 0)
	    break;
	
	v.clear();
	
	for(int i=0; i<n; ++i)
	{
	    scanf("%d", &e);
	    v.push_back(e);
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n-1; ++i)
	    printf("%d ", v[i]);
	printf("%d\n", v[n-1]);
    }
    
    return 0;
}