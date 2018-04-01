#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)

using namespace std;
int main(){
    int SZ,V,x,y,w,i,j,vi;
    scanf("%d",&SZ);
    int volcan[SZ][SZ];
    loop(i,0,SZ)memset(volcan[i],0, sizeof volcan[i]);
    int res=0,pr=0;
    scanf("%d",&V);
    loop(vi,0,V){
        scanf("%d%d%d",&x,&y,&w);
        int Ji = x-w+1,Jf =x+w+2;
        int Ii = x-w,If =x+w+1;
        int k = 0;
        /*
        10
        1
        4 5 6
        */
        printf("%d %d %d %d\n",Ii,If,Ji,Jf);
        while (k!=w){
            Ji++;Jf--;
            Ii++;If--;
            loop(i,Ii,If){
                loop(j,Ji,Jf){
                    if (i>=0 && i<SZ  && j>=0  && j<SZ){
                        if (volcan[i][j]==0)volcan[i][j] = k+1;
                        else volcan[i][j] += k+1;

                        res = max(volcan[i][j],res);
                    }
                    if (i<0)break;
                }
            }
            k++;
        }
        loop(i,0,SZ)loop(j,0,SZ){
            if (SZ-1==j)printf("%d\n",volcan[i][j]);
            else printf("%d ",volcan[i][j]);
        }
        puts("");
    }
    printf("%d",res);
    return 0;
}
