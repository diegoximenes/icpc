#include<cstdio>
#include<vector>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int n, lenmes, nants, a, mini, maxi, smaisdir, smaisesq;
    double scol, tcol;
    vector<int> s;
    scanf("%d", &n);
    
    while(n--)
    {
	s.clear();
	
	scanf("%d %d", &lenmes, &nants);
	
	for(int i=0; i<nants; ++i)
	{
	    scanf("%d", &a);
	    s.push_back(a);
	}
	
	//calcula minimo
	mini = 0;
	for(int i=0; i<nants; ++i)
	    mini = max(min(s[i], lenmes - s[i]), mini);
	
	//calcula maximo
	maxi = 0;
	//sem colisao
	smaisdir = 0;
	smaisesq = INT_MAX;
	for(int i=0; i<nants; ++i)
	{
	    maxi = max(lenmes - s[i], s[i]);
	    smaisesq = min(smaisesq, s[i]);
	    smaisdir = max(smaisdir, s[i]);
	}
	//printf("smaisesq = %d, smaisdir = %d\n", smaisesq, smaisdir);
	//faz colidir
	//tcol = ceil((smaisdir - smaisesq)/2);
	tcol = ((double)smaisdir - (double)smaisesq)/(double)2;
	scol = (double)smaisesq + tcol;
	//printf("tcol = %f, scol = %f\n", tcol, scol);
	maxi = max((int)ceil(tcol + ((double)lenmes - scol)), (int)ceil(tcol + scol)); 
	
	printf("%d %d\n", mini, maxi);
    }
    
    return 0;
}