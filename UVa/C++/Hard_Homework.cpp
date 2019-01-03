#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;

int main(){
    int cases,i;
    scanf("%d",&cases);
    while (cases--){
        int sz;scanf("%d",&sz);
        long long res=1;
        long n;
        loop(i,0,sz){
            scanf("%ld",&n);
            res*=n;
        }
        printf("%ld",res);


    }
    return 0;
}
