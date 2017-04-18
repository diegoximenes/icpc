#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 50010

int main()
{
	int b, m, vb[MAX], vm[MAX], t;

	scanf("%d", &t);
	for(int tc=0; tc<t; ++tc)
	{
		bool meg = 0, baj = 0;
		scanf("%d", &b);
		for(int i=0; i<b; ++i) scanf("%d", &vb[i]);
		scanf("%d", &m);
		for(int i=0; i<m; ++i) scanf("%d", &vm[i]);

		sort(vb, vb+b);
		sort(vm, vm+m);

		for(int ib=b-1, im=m-1; ib>=0 && im>=0; --ib, --im)
		{
			if(vb[ib] > vm[im])
			{
				baj = 1;
				break;
			}
			else if(vm[im] > vb[ib])
			{
				meg = 1;
				break;
			}
		}

		if(baj)
			puts("Bajtocja");
		else if(meg)
			puts("Megabajtolandia");
		else if(b > m)
			puts("Bajtocja");
		else if(m > b)
			puts("Megabajtolandia");
		else puts("Draw");
	}

	return 0;
}
