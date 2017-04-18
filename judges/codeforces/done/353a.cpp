#include<cstdio>
using namespace std;

int main()
{
	int n, su = 0, sl = 0, u, l;
	bool evenu = 0, oddu = 0, evenl = 0, oddl = 0;

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d %d", &u, &l);
		su += u; sl += l;

		if(u%2 == 0 && l%2 == 1) evenu = 1, oddl = 1;
		else if(u%2 == 1 && l%2 == 0) oddu = 1, evenl = 1;
	}

	if(su%2 == 0 && sl%2 == 0) puts("0");
	else if((su%2==0 && sl%2==1) || (su%2==1 && sl%2==0)) puts("-1");
	else if(su%2 == 1 && oddu && evenl && n > 1) puts("1");
	else if(sl%2 == 1 && oddl && evenu && n > 1) puts("1");
	else puts("-1");

	return 0;
}
