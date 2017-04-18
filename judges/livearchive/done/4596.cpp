#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define MAX 105
#define EPS 1e-9

int main()
{
	char gun[MAX];

	while(gets(gun) != NULL)
	{
		int count0 = 0, next0 = 0, n = strlen(gun);
		
		for(int i=0; i<n; ++i)
		{
			if(gun[i] == '0') ++count0;
			if(gun[i] == '0' && gun[(i+1)%n] == '0') ++next0;
		}

		double shoot = (double)next0/(double)count0, rotate = (double)count0/(double)n;
		if(fabs(shoot - rotate) < EPS) puts("EQUAL");
		else if(shoot > rotate) puts("SHOOT");
		else puts("ROTATE");
	}

	return 0;
}
