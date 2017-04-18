#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>

typedef struct 
{
    char name[40];
    int point, win, loss, tie, goalscored, goalagainst, gameplayed;
}Team;

int cmp(const void *a, const void *b)
{
    Team *t1 = (Team *)a;
    Team *t2 = (Team *)b;
    
    if(t1->point > t2->point) return -1;
    else if(t1->point < t2->point) return 1;
    else if(t1->win > t2->win) return -1;
    else if(t1->win < t2->win) return 1;
    else if((t1->goalscored - t1->goalagainst) > (t2->goalscored - t2->goalagainst)) return -1;
    else if((t1->goalscored - t1->goalagainst) < (t2->goalscored - t2->goalagainst)) return 1;
    else if(t1->goalscored > t2->goalscored) return -1;
    else if(t1->goalscored < t2->goalscored) return 1;
    else if(t1->gameplayed < t2->gameplayed) return -1;
    else if(t1->gameplayed > t2->gameplayed) return 1;
    else
    {
	char n1[40], n2[40];
	strcpy(n1, t1->name);
	strcpy(n2, t2->name);
	for(int i=0; i<strlen(n1); ++i)
	    n1[i] = tolower(n1[i]);
	for(int i=0; i<strlen(n2); ++i)
	    n2[i] = tolower(n2[i]);
		    
	if(strcmp(n1, n2) < 0) return -1;
	else if(strcmp(n1, n2) > 0) return 1;
	else return 0;
    }
}

int main()
{
    int n, i, j, k, t, g, goal1, goal2;
    char tourname[110], teamname1[40], teamname2[40];
    Team v[30], t1, t2;
    
    scanf("%d", &n);
    getchar();
    
    for(i=0; i<n; ++i)
    {
	gets(tourname);
	
	//puts(tourname);
	
	scanf("%d", &t);
	getchar();
	
	//printf("t = %d\n", t);
	
	for(j=0; j<t; ++j)
	{
	    gets(v[j].name);
	    //puts(v[j].name);
	    v[j].point = v[j].win = v[j].loss = v[j].tie = v[j].goalscored = v[j].goalagainst = v[j].gameplayed = 0;
	}
    
	scanf("%d", &g);
	getchar();
	
	//printf("g = %d\n", g);
	
	for(j=0; j<g; ++j)
	{
	    scanf("%[^#]s", teamname1);
	    getchar();
	    scanf("%d", &goal1);
	    getchar();
	    scanf("%d", &goal2);
	    getchar();
	    scanf("%[^\n]s", teamname2);
	    getchar();
	    
	    //printf("%s - %d:%d - %s\n", teamname1, goal1, goal2, teamname2);
	    
	    for(k=0; k<t; ++k)
	    {
		if(!strcmp(v[k].name, teamname1))
		{
		    if(goal1 > goal2)
		    {
			v[k].point += 3;
			v[k].win++;
		    }
		    else if(goal1 == goal2)
		    {
			v[k].point++;
			v[k].tie++;
		    }
		    else
			v[k].loss++;
			
		    
		    v[k].goalscored += goal1;
		    
		    v[k].goalagainst += goal2;
		    
		    v[k].gameplayed++;
		}
		
		if(!strcmp(v[k].name, teamname2))
		{
		    if(goal1 < goal2)
		    {
			v[k].point += 3;
			v[k].win++;
		    }
		    else if(goal1 == goal2)
		    {
			v[k].point++;
			v[k].tie++;
		    }
		    else
			v[k].loss++;
			
		    
		    v[k].goalscored += goal2;
		    
		    v[k].goalagainst += goal1;
		    
		    v[k].gameplayed++;
		}
	    }
	}
	
	qsort(v, t, sizeof(Team), cmp);
	
	puts(tourname);
	for(j=0; j<t; ++j)
	    printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", j+1, v[j].name, v[j].point, v[j].gameplayed, v[j].win, v[j].tie, v[j].loss, v[j].goalscored - v[j].goalagainst, v[j].goalscored, v[j].goalagainst);
	
	if(i != n-1)
	    puts("");
    }
    
    return 0;
}