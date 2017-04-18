#include<cstdio>
#include<cstring>

void branco(int s)
{
    int k;
    
    printf(" ");
    for(k=0; k<s; ++k)
	printf(" ");
    printf(" ");
}

void meio(int s)
{
    int k;
    
    printf(" ");
    for(k = 0; k < s; ++k)
	printf("-");
    printf(" ");
}

void ladodireito(int s)
{
    int k;
    
    printf(" ");
    for(k = 0; k < s; ++k)
	printf(" ");
    printf("|");
}

void ladoesquerdo(int s)
{
    int k;
    
    printf("|");
    for(k = 0; k < s; ++k)
	printf(" ");
    printf(" ");
}

void doislados(int s)
{
    int k;
    
    printf("|");
    for(k = 0; k < s; ++k)
	printf(" ");
    printf("|");
}

int main()
{
    int s, i, j, k;
    bool flag;
    char n[9];
    
    flag = 0;
    while(1)
    {
	scanf("%d%s", &s, &n);
	
	if(s == 0) break;
	
	if(flag)
	    printf("\n");
	flag = 1;
	
	for(i=0; i < 2*s + 3; ++i)
	    for(j=0; j< strlen(n); ++j)
	    {
		//printf("n[j] = %caaa", n[j]);
		switch(n[j])
		{
		    case '0':
			if((i == 0) || (i == 2*s + 2))
			    meio(s);
			else if(i == s + 1)
			    branco(s);
			else
			    doislados(s);
			break;
		    case '1':
			if((i == 0) || (i == s + 1) || (i == 2*s + 2))
			    branco(s);
			else
			    ladodireito(s);
			break;
		    case '2':
			if((i == 0) || (i == s + 1) || (i == 2*s + 2))
			    meio(s);
			else if(i < s + 1)
			    ladodireito(s);
			else
			    ladoesquerdo(s);
			break;
		    case '3':
			if((i == 0) || (i == s + 1) || (i == 2*s + 2))
			    meio(s);
			else
			    ladodireito(s);
			break;
		    case '4':
			if((i == 0) || (i == 2*s + 2))
			    branco(s);
			else if(i == s + 1)
			    meio(s);
			else if(i < s + 1)
			    doislados(s);
			else
			    ladodireito(s);
			break;
		    case '5':
			if((i == 0) || (i == s + 1) || (i == 2*s + 2))
			    meio(s);
			else if(i < s + 1)
			    ladoesquerdo(s);
			else
			    ladodireito(s);
			break;
		    case '6':
			if((i == 0) || (i == s + 1) || (i == 2*s + 2))
			    meio(s);
			else if(i < s + 1)
			    ladoesquerdo(s);
			else
			    doislados(s);
			break;
		    case '7':
			if(i == 0)
			    meio(s);
			else if((i == s+1) || (i == 2*s + 2))
			    branco(s);
			else
			    ladodireito(s);
			break;
		    case '8':
			if((i == 0) || (i == s + 1) || (i == 2*s + 2))
			    meio(s);
			else
			    doislados(s);
			break;
		    case '9':
			if((i == 0) || (i == s + 1) || (i == 2*s + 2))
			    meio(s);
			else if(i < s+1)
			    doislados(s);
			else
			    ladodireito(s);
			break;
		}
		
		if(j != strlen(n) - 1)
		    printf(" ");
		else
		    printf("\n");
	    }
    }
    printf("\n");
    
    return 0;
}