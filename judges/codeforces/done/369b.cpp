#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 1010

int a[MAX], n, k, l, r, sk, sn, actualsk, actualsn, d;

int main()
{
	scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sn, &sk);
	
	for(int i=0; i<n; ++i) a[i] = l;
	actualsn = l*n; actualsk = l*k;
	
	d = (sk - actualsk)/k;
	for(int i=0; i<k; ++i) a[i] += d, actualsk += d, actualsn += d;
	for(int i=0; actualsk != sk; ++i) a[i]++, actualsk++, actualsn++;
	int mink = *min_element(a, a+k);
		
	for(int i=k; i<n && actualsn < sn; ++i)
	{
		d = min(r - a[i], sn - actualsn);
		if(d + a[i] > mink) d = mink - a[i];
		a[i] += d; actualsn += d;
	}
	
	printf("%d", a[0]);
	for(int i=1; i<n; ++i) printf(" %d", a[i]);
	puts("");

	return 0;
}
