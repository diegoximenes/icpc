#include<cstdio>
#include<vector>
using namespace std;

#define pb push_back

int main()
{
	int t, n1, n2, rn1, rn2, sum;

	scanf("%d", &t);
	while(t--)
	{
		vector<int> nv1, nv2;
		scanf("%d %d", &n1, &n2);
		while(n1 > 0)
		{
			nv1.pb(n1%10);
			n1 /= 10;
		}
		while(n2 > 0)
		{
			nv2.pb(n2%10);
			n2 /= 10;
		}
		rn1 = rn2 = 0;
		for(int i=nv1.size()-1, k=1; i>=0; --i, k*=10) rn1 += nv1[i]*k;
		for(int i=nv2.size()-1, k=1; i>=0; --i, k*=10) rn2 += nv2[i]*k;
		sum = rn1 + rn2;
		
		bool first = 1;
		while(sum > 0)
		{
			if(!(first && sum%10 == 0))
			{
				printf("%d", sum%10);
				first = 0;
			}
			sum /= 10;
		}
		puts("");
	}

	return 0;
}
