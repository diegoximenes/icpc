#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int t, pro, con, minimal, maximal;
	char where[15];

	scanf("%d", &t);
	while(t--)
	{
		scanf(" The Machinegunners played %s game, scored %d goals, and conceded %d goals.", where, &pro, &con);

		if(strcmp(where, "home") == 0)
		{
			if(con > pro)
			{
				minimal = con - pro;
				if(minimal < con) minimal++;
			}
			else if((con == pro && pro == 0) || con < pro) minimal = 0;
			else minimal = 1;

			if(pro > con || pro == con)
			{
				maximal = 30 - (pro - con);
				if(maximal > con) maximal--;
			}
			else maximal = 30;
		}
		else
		{
			if(pro > con || pro == con) minimal = 0;
			else minimal = con - pro;

			if(pro > con || pro == con) maximal = 30 - (pro - con);
			else maximal = 30;
		}

		printf("%d %d\n", minimal, maximal);
	}

	return 0;
}
