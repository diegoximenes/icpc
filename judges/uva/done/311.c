#include<stdio.h>

int main()
{
	int v[7], count, falta1, falta2, i, j;
	
	while(1)
	{
		scanf("%d %d %d %d %d %d", &v[1], &v[2], &v[3], &v[4], &v[5], &v[6]);
		
		if((v[1] == 0) && (v[2] == 0) && (v[3] == 0) && (v[4] == 0) && (v[5] == 0) && (v[6] == 0))
			break;
		
		count = 0;
		
		while(v[6])
		{
			--v[6];
			++count;
		}
		
		while(v[5])
		{
			--v[5];
			
			falta1 = 6*6 - 5*5;
			
			while(falta1 && v[1])
			{
				--v[1];
				--falta1;
			}
			++count;
		}
		
		while(v[4])
		{
			--v[4];
			
			i = 0;
			
			while((i<5) && v[2])
			{
				--v[2];
				++i;
			}
			
			falta1 = 6*6 - 4*4 - i*2*2;
			
			while(falta1 && v[1])
			{
				--v[1];
				--falta1;
			}
			
			++count;
		}
		
		while(v[3])
		{
			i = 0;
			while((i<4) && v[3])
			{
				--v[3];
				++i;
			}
			
			if(i==2)
				falta2 = 3;
			else if(i == 1)
				falta2 = 5;
			else if(i == 3)
				falta2 = 1;
			else
				falta2 = 0;
			
			j = 0;
			while((j<falta2) && (v[2]))
			{
				--v[2];
				++j;
			}
			
			falta1 = 6*6 - 3*3*i - 2*2*j;
			while(falta1 && v[1])
			{
				--v[1];
				--falta1;
			}
			++count;
		}
		
		while(v[2])
		{
			i=0;
			while(i<9 && v[2])
			{
				--v[2];
				++i;
			}
			
			falta1 = 6*6 - 2*2*i;
			while(falta1 && v[1])
			{
				--v[1];
				--falta1;
			}
			++count;
		}
		
		while(v[1])
		{
			i=0;
			while((i<36) && v[1])
			{
				--v[1];
				++i;
			}
			++count;
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}