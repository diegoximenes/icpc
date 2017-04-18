#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
    int n, x, y, rook=0, bishop=0, queen=0, king=0, knight=0;

    scanf("%d %d %d", &n, &x, &y);
    rook = (n - x) + (x - 1) + (n - y) + (y - 1);
    bishop = min(x-1, y-1) + min(n-x, n-y) + min(x-1, n-y) + min(n-x, y-1);
    queen = rook + bishop;

    king = min(x-1, 1) + min(n-x, 1) + min(y-1, 1) + min(n-y, 1);
    if(x-1 > 0 && y-1 > 0) king++;
    if(x-1 > 0 && y+1 <= n) king++;
    if(x+1 <= n && y-1 > 0) king++;
    if(x+1 <= n && y+1 <= n) king++;

    if(x+2 <= n && y+1 <= n) knight++;
    if(x+2 <= n && y-1 > 0) knight++;
    if(x-2 > 0 && y+1 <= n) knight++;
    if(x-2 > 0 && y-1 > 0) knight++;
    if(x+1 <= n && y+2 <= n) knight++;
    if(x+1 <= n && y-2 > 0) knight++;
    if(x-1 > 0 && y+2 <= n) knight++;
    if(x-1 > 0 && y-2 > 0) knight++;

    printf("King: %d\n", king);
    printf("Knight: %d\n", knight);
    printf("Bishop: %d\n", bishop);
    printf("Rook: %d\n", rook);
    printf("Queen: %d\n", queen);

    return 0;
}