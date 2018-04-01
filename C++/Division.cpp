#include <bits/stdc++.h>
#define loop(i,a,b) for (i=a,i<b,i++)
using namespace std;

int main() {
    int Query, x, y, x1, y1;
    while(scanf("%d", &Query) == 1 && Query) {
        scanf("%d %d", &x, &y);
        while(n--){
            scanf("%d %d", &x1, &y1);
            if(x1 > x && y1 > y) puts("NE");
            else if(x1 < x && y1 > y)puts("NO");
            else if(x1 < x && y1 < y) puts("SO");
            else if(x1 == x || y1 == y)puts("divisa");
            else puts("SE");
        }
    }
    return 0;
}
