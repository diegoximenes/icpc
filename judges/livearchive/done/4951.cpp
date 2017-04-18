#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

#define mp make_pair

int main()
{
	int t, n, x, p;
	char op[100];

	scanf("%d", &t);
	while(t--)
	{
		multiset< pair<int, int> > buy, sell;
		int deal = -1;

		scanf("%d", &n);
		while(n--)
		{
			scanf(" %s %d shares at %d ", op, &x, &p);
			if(strcmp(op, "buy") == 0) buy.insert(mp(-p, x));
			else sell.insert(mp(p, x));
			
			while(1)
			{
				if(sell.empty() || buy.empty()) break;

				pair<int, int> bid = *buy.begin();
				bid.first *= -1;
				pair<int, int> ask = *sell.begin();

				if(ask.first > bid.first) break;
				
				//printf("0: ask= (%d, %d), bid= (%d, %d)\n", ask.first, ask.second, bid.first, bid.second);
				
				sell.erase(sell.begin()); buy.erase(buy.begin());

				deal = ask.first;
				int qtd = min(ask.second, bid.second);
				ask.second -= qtd; bid.second -= qtd;
				if(ask.second > 0) sell.insert(ask);
				if(bid.second > 0) bid.first *= -1, buy.insert(bid);

				//printf("ask= (%d, %d), bid= (%d, %d)\n", ask.first, ask.second, bid.first, bid.second);
			}

			if(!sell.empty()) printf("%d ", sell.begin()->first);
			else printf("- ");

			if(!buy.empty()) printf("%d ", -buy.begin()->first);
			else printf("- ");
			
			if(deal == -1) puts("-");
			else printf("%d\n", deal);
		}
	}

	return 0;
}

