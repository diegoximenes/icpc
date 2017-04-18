#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int m = 0, h = 0, ang;
	bool can[185];
	memset(can, 0, sizeof(can));
	for(int i=1; i<=720; ++i)
	{
		m+=6; if(i%60 == 0) m = 0;
		if(i%12 == 0) h+=6;

		can[min(abs(h-m), 360-abs(h-m))] = 1;
	}

	while(scanf("%d", &ang) == 1)
		puts(can[ang] ? "Y" : "N");

	return 0;
}
