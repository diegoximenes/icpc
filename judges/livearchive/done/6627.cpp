#include<cstdio>
#include<cstring>
using namespace std;

inline bool thirtyOne(int m)
{
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 1;
	return 0;
}

inline bool thirty(int m)
{
	if(m != 2 && !thirtyOne(m)) return 1;
	return 0;
}

inline bool bissestG(int y)
{
	if(y%4) return 0;
	if(y%100 == 0)
	{
		if(y%400 == 0) return 1;
		return 0;
	}
	return 1;
}

inline bool bissestJ(int y)
{
	return (y%4 == 0);
}

int main()
{
	char s[50];
	int yearJ, monthJ, dayJ;

	while(scanf(" %s ", s) == 1)
	{
		char *token;
		token = strtok(s, "-");
		for(int k=0; token != NULL; k++)
		{
			int x = 0;
			for(int i=strlen(token)-1, j=1; i>=0; --i, j*=10) x += j*(token[i] - '0');

			//printf("token= %s, x= %d\n", token, x);

			if(k == 0) yearJ = x;
			else if(k == 1) monthJ = x;
			else dayJ = x;

			token = strtok(NULL, "-");
		}
		
		//printf("dayJ= %d, monthJ= %d, yearJ= %d\n", dayJ, monthJ, yearJ);
			
		int days = 0;
		for(int i=1; i<yearJ ; ++i)
			if(bissestJ(i) && !bissestG(i))
				++days;
		if(monthJ > 2 && bissestJ(yearJ) && !bissestG(yearJ)) ++days;
		
		int d = dayJ, m = monthJ, y = yearJ;
		if(monthJ == 2 && dayJ == 29 && bissestJ(yearJ) && !bissestG(yearJ)) d = 1, m++;
		
		for(int i=0; i<days-1; ++i)
		{
			d++;
			if(thirtyOne(m) && d == 32) d = 1, m++;
			else if(thirty(m) && d == 31) d = 1, m++;
			if(m == 2 && !bissestG(y) && d == 29) d = 1, m++;
			else if(m == 2 && bissestG(y) && d == 30) d = 1, m++;
			if(m == 13) m = 1, y++;
			
			//printf("d= %d, m= %d, y= %d, dj= %d, mj= %d, yj= %d\n", d, m, y, dJ, mJ, yJ);
		}
		
		if(y < 10) printf("000");
		else if(y < 100) printf("00");
		else if(y < 1000) printf("0");
		printf("%d-", y);

		if(m < 10) printf("0");
		printf("%d-", m);

		if(d < 10) printf("0");
		printf("%d\n", d);
	}

	return 0;
}
