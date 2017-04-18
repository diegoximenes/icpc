#include<cstdio>
using namespace std;

const int dig[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void highest(int n)
{
	if(n%2 == 0)
	{
		while(n != 0)
		{
			putchar('1');
			n -= 2;
		}
	}
	else 
	{
		putchar('7');
		n -= 3;
		while(n != 0)
		{
			putchar('1');
			n -= 2;
		}
	}
}

int countDigits(int n)
{
	return n/7 + ((n%7 == 0) ? 0 : 1);
}

void lowest(int n)
{
	int countDig = countDigits(n); 	
	bool first = 1;	
	for(int i=0; i<countDig; ++i)
		for(int j=0; j<10; ++j)
			if(n - dig[j] >= 0 && countDigits(n - dig[j]) == countDig - i - 1)
			{
				if(first && j==0) continue;
				first = 0;
				printf("%d", j);
				n -= dig[j];
				break;
			}
}

int main()
{
	int tc, n;

	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n);
		lowest(n); putchar(' '); highest(n); puts("");
	}
		
	return 0;
}
