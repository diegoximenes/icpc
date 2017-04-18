#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

int main()
{
	char line[2000];
	char *word, actual, last;
	
	while(1)
	{
		bool solved = 0;
		gets(line);
		if(strcmp(line, "*") == 0) break;

		last = 0;
		word = strtok(line, " ");
		while(word != NULL)
		{
			actual = tolower(word[0]);
			if(last != 0 && last != actual)
			{
				solved = 1;
				puts("N");
				break;
			}
			word = strtok(NULL, " ");
			last = actual;
		}

		if(!solved) puts("Y");
	}

	return 0;
}
