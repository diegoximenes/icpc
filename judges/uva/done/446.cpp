#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
using namespace std;

inline int toNum(char c)
{
	if(isdigit(c)) return c - '0';
	else return 10 + c - 'A';
}

int main()
{
	char hex1[10], hex2[10], op;
	
	int t;
	scanf("%d", &t);
	for(int tc=0; tc < t; ++tc)
	{
		scanf("%s %c %s", hex1, &op, hex2);
		int len1 = strlen(hex1), len2 = strlen(hex2), dec1 = 0, dec2 = 0;

		for(int i=len1-1; i>=0; --i) dec1 += pow(16, len1-i-1)*toNum(hex1[i]);
		for(int i=len2-1; i>=0; --i) dec2 += pow(16, len2-i-1)*toNum(hex2[i]);

		for(int i= 12; i>=0; --i) 
		{
			if((1 << i) & dec1) putchar('1');
			else putchar('0');
		}
		printf(" %c ", op);
		for(int i= 12; i>=0; --i) 
		{
			if((1 << i) & dec2) putchar('1');
			else putchar('0');
		}
		if(op == '+') printf(" = %d\n", dec1 + dec2);
		else printf(" = %d\n", dec1 - dec2);
	}

	return 0;
}
