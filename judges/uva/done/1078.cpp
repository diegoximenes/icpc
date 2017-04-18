#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char line[50];

	gets(line);
	while(1)
	{
		char c = 0;
		gets(line);
		if(strcmp(line, "___________") == 0) break;

		if(line[9] == 'o') c |= (1 << 0);
		if(line[8] == 'o') c |= (1 << 1);
		if(line[7] == 'o') c |= (1 << 2);
		if(line[5] == 'o') c |= (1 << 3);
		if(line[4] == 'o') c |= (1 << 4);
		if(line[3] == 'o') c |= (1 << 5);
		if(line[2] == 'o') c |= (1 << 6);
		if(line[1] == 'o') c |= (1 << 7);
		
		putchar(c);
	}
}
