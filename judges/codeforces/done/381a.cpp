#include<cstdio>
using namespace std;

int main()
{
	int n, v[1010], sereja = 0, dima = 0;

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	int i = 0, j = n-1;
	
	bool isSereja = 1;
	while(i <= j)
	{
		int aux;
		if(v[i] > v[j]) aux = v[i], ++i;
		else aux = v[j], --j;

		if(isSereja) sereja += aux, isSereja = 0;
		else dima += aux, isSereja = 1;
	}

	printf("%d %d\n", sereja, dima);

	return 0;
}
