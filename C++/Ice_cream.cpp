#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)

using namespace std;

int ci[10010];
int main(){
    int cases,m,n,i,j;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&m,&n);
        memset(ci,0,sizeof ci);
        loop(i,0,n)scanf("%d",&ci[i]);
        int r1,r2;
        bool ban = true;
        loop(i,0,n){
            loop(j,i+1,n){
                if (ci[i]+ci[j]==m){
                  r1=i;r2=j;
                  ban = false;
                  break;
                }
            }if(!ban)break;
        }

        printf("%d %d\n",r1+1,r2+1);
    }
    return 0;
}
