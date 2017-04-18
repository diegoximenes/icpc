#include<cstdio>
#include<iostream>
#include<utility>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define MAX 100000

int v[300*MAX];
pair<int, pair<int, int> > change[MAX];

int main()
{
	int n, op, l, c, q;
	ll query;

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &op);
		if(op == 1) scanf("%d", &l), change[i] = mp(1, mp(l, 0));
		else scanf("%d %d", &l, &c), change[i] = mp(2, mp(l, c));
	}

	ll actual = 0, lastactual;
	int last;
	bool printed = 0;
	scanf("%d", &q);
	for(int i=0, j=0; i<q; ++i)
	{
		cin >> query;
		bool solved = 0;
		
		while(actual < query)
		{
			if(change[j].first == 1)
			{
				if(actual < MAX-1) v[actual] = change[j].second.first;
				++actual;
				if(actual == query) last = change[j].second.first, solved = 1;
			}
			else
			{
				l = change[j].second.first;
				c = change[j].second.second;
				if(actual < MAX-1)
				{
					int cnt = 0;
					for(int k=0; k<c; ++k)
					{
						for(int m=0; m<l; ++m)
						{
							++cnt;
							v[actual + k*l + m] = v[m];
							if(actual + k*l + m + 1 == query) last = v[query - 1], solved = 1;
							//printf("query= %d, actual= %d, actual + asads= %d\n", query, actual, actual + k*l + m + 1);
						}

						if(actual > MAX-1)
						{
							int rest = (c - k - 1)*l;
							lastactual = actual;
							actual += rest + cnt; 
							cnt = 0;
							if(actual >= query && !solved) last = v[(query - lastactual - 1)%l], solved = 1;
							break;
						}
					}

					actual += cnt;
				}
				else
				{
					lastactual = actual;
					actual += l*c;
					if(actual >= query) last = v[(query - lastactual - 1)%l], solved = 1;
				}
			}
			++j;
		}

		if(!solved)
		{
			if(actual <= MAX) last = v[query-1];
			else last = v[(query - lastactual - 1)%l];
		}
		
		if(!printed) printf("%d", last), printed = 1;
		else printf(" %d", last);
	}
	puts("");

	return 0;
}
