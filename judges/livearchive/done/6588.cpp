#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 10005

int v[MAX];

void myswap(int i, int j, int len)
{
	for(int k=0; k<len; ++k) swap(v[i+k], v[j+k]);
}

int main()
{
	int t, n;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i) scanf("%d", &v[i]), --v[i];
	
		vector< pair<int, int> > out;
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
				if(v[j] == i)
				{
					if(j - i <= n - j) myswap(i, j, j - i), out.pb(mp(i, j + (j - i - 1)));
					else
					{
						int l = n - 2*((n - i)/2) , r =  n - (n - i)/2;
						myswap(l, r, (n - i)/2); 
						out.pb(mp(l, r + (n - i)/2 - 1));
						--i;
					}

					break;
				}
		
		printf("%d\n", (int)out.size());
		for(int i=0; i<(int)out.size(); ++i) printf("%d %d\n", out[i].first + 1, out[i].second + 1);
	}

	return 0;
}
