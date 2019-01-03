#include <bits/stdc++.h>

using namespace std;
int main(){
    long a,b,c,d;
    while((scanf("%ld%ld%ld%ld",&a,&b,&c,&d))==4){
        long r = a+d;
        long r1 = c+b;
        long ans = abs(r-r1);
        printf("%ld\n",ans);

    }
    return 0;
}
