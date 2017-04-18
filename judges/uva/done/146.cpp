#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char perm[50];
    
    while(scanf("%s", perm))
    {
	if(!strcmp(perm, "#"))
	    break;
	
	if(!next_permutation(perm, perm + strlen(perm)))
	    printf("No Successor\n");
	else
	    printf("%s\n", perm);
    }
    
    return 0;
}