#include<stdio.h>

int toMinute(int h, int m)
{
	return h*60 + m;
}

int main()
{
	int n, hsr, msr, hss, mss, hs, ms, hf, mf;
	
	while(scanf("%d", &n) && n)
	{
		int time = 0, night = 0, printed = 0, delta, sr, ss, finish, start, l, r;
		while(n--)
		{
			scanf("%d:%d %d:%d %d:%d %d:%d", &hsr, &msr, &hss, &mss, &hs, &ms, &hf, &mf);
			if(!printed)
			{
				sr = toMinute(hsr, msr);
				ss = toMinute(hss, mss);
				start = toMinute(hs, ms);
				finish = toMinute(hf, mf);
				delta = finish - start;
				
				if(delta > 2*60)
				{
					puts("NON");
					printed = 1;
				}
				time += delta;
				
				if((start >= sr) && (finish <= ss))
					continue;
				if((start >= ss) || (finish <= sr))
				{
					l = start;
					r = finish;
				}
				else if((start <= sr) && (finish >= ss))
				{
					if(sr - start + finish - ss >= (double)delta/2.0)
						night += delta;
					continue;
				}
				else if((start < sr) && (finish <= ss))
				{
					l = start;
					r = sr;
				}
				else if((start > sr) && (finish > ss))
				{
					l = ss;
					r = finish;
				}
				
				if(r - l >= (double)delta/2.0)
					night += delta;
			}
		}
		if(!printed)
		{
			if((time >= 50*60) && (night >= 10*60))
				puts("PASS");
			else
				puts("NON");
		}
	}
	
	return 0;
}