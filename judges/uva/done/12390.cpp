#include<cstdio>
#include<cmath>
#include<set>
using namespace std;

int main()
{
   int n, b, nb;
   float v;
   set< pair< float, pair<float, int> > > heap;
   pair<float, int> p;
   
   while(1)
   {
	 scanf("%d %d", &n, &b);
	 
	 if((n == -1) && (b == -1))
	    break;
	 	 
	 heap.clear();
	 
	 b -= n;
	 
	 while(n--)
	 {
	    scanf("%f", &v);
	    heap.insert(make_pair(-v, make_pair(v, 1)));
	 }
	 
	 while(b--)
	 {
	    p = heap.begin()->second;
	    v = p.first;
	    nb = p.second;
	    
	    heap.erase(heap.begin());
	    
	    ++nb;
	    heap.insert(make_pair(-(v/(float)nb), make_pair(v, nb)));
	 }
	 
	 printf("%d\n", (int)ceil((-(heap.begin())->first)));
   }
   
   return 0;
}