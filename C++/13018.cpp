#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i<=b; ++i)


using namespace std;

int main(){
    int n,m,flang=0;
    while(scanf("%d %d",&n,&m)==2){
        if(flang)puts("");
        int maxi = max(n,m);
        int mini = min(n,m);
        loop(i,mini+1,maxi+1){
            printf("%d\n",i);
        }
        flang = 1;
    }
    return 0;
}
