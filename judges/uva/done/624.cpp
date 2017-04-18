#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

#define TMAX 25

int main()
{
	int t, n, track[TMAX], i, w;
	vector< vector<int> > pd;

	vector<int> v;
	v.clear();
	pd.assign(TMAX, v);
	
	while(scanf("%d %d", &n, &t) == 2)
	{
		v.assign(n+1, 0);
		pd.assign(t+1, v);
		
		for(i=1; i<=t; ++i)
			scanf("%d", &track[i]);
		
		for(i=1; i<=t; ++i)
			for(w=0; w<=n; ++w)
			{
				if(track[i] > w)
					pd[i][w] = pd[i-1][w];
				else
					pd[i][w] = max(pd[i-1][w], track[i] + pd[i-1][w - track[i]]);
			}
		
		i = t;
		w = n;
		stack<int> p;
		while(i>0)
		{
			if(pd[i][w] == pd[i-1][w-track[i]] + track[i])
			{
				//p.push(track[i]);
				printf("%d ", track[i]);
				w = w-track[i];
			}
			i = i-1;
		}
		
		/*while(!p.empty())
		{
			printf("%d ", p.top());
			p.pop();
		}*/
		printf("sum:%d\n", pd[t][n]);
	}
	
	return 0;
}