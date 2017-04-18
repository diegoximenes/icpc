#include<cstdio>
using namespace std;

#define MAX 100010

int main()
{
	int n, p1, p2, v[MAX];

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	scanf("%d %d", &p1, &p2);
	--p1, --p2;

	int cnt1 = 0, cnt2 = 0;
	if(p1 < p2)
	{
		while(1)
		{
			if(p1 == p2 || p1 == p2 - 1) break;
			p1++; p2--;
		}
		for(; p1>=0; --p1) cnt1 += v[p1], v[p1] = 0;
		for(; p2<n; ++p2) cnt2 += v[p2];
	}
	else if(p1 > p2)
	{
		while(1)
		{
			if(p1 == p2 || p2 == p1 - 1) break;
			p1--; p2++;
		}
		for(; p1<n; ++p1) cnt1 += v[p1], v[p1] = 0;
		for(; p2>=0; --p2) cnt2 += v[p2];
	}
	else
	{
		for(int i=p1; i<n; ++i) cnt1 += v[i];
		for(int i=0; i<p1; ++i) cnt2 += v[i];
		
		int auxcnt1 = 0, auxcnt2 = 0;
		for(int i=0; i<=p1; ++i) auxcnt1 += v[i];
		for(int i=p2+1; i<n; ++i) auxcnt2 += v[i];

		if(cnt1 < auxcnt1) cnt1 = auxcnt1, cnt2 = auxcnt2;
		else if(cnt1 == auxcnt1 && auxcnt2 < cnt2) cnt1 = auxcnt1, cnt2 = auxcnt2;
	}

	printf("%d %d\n", cnt1, cnt2);

	return 0;
}
