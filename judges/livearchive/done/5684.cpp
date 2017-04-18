#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int tc, n;
	char line[1000];
	
	gets(line);
	sscanf(line, "%d", &tc);
	for(int t=1; t<=tc; ++t)
	{
		int present = 0, home = 0, absent = 0, remedial = 0;
		
		gets(line);
		sscanf(line, "%d", &n);
		for(int i=0; i<n; ++i)
		{
			bool name = 1, solved = 0;
			int count = 0;

			gets(line);
			char *pch = strtok(line, " ");
			while(pch != NULL && !solved)
			{
				if(!name)
				{
					if(strcmp(pch, "yes") == 0 || strcmp(pch, "y") == 0)
					{
						if(count == 0)
						{
							++present; solved = 1;
						}
						else if(count < 5)
						{
							++home; solved = 1;
						}
					}
					++count;
				}
				pch = strtok(NULL, " ");
				name = 0;
			}
			if(count == 0) ++absent;
			else if(!solved) ++ remedial;
		}
		printf("Roll-call: %d\n", t);
		printf("Present: %d out of %d\n", present, n);
		printf("Needs to study at home: %d out of %d\n", home, n);
		printf("Needs remedial work after school: %d out of %d\n", remedial, n);
		printf("Absent: %d out of %d\n", absent, n);
	}

	return 0;
}
