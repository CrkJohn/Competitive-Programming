#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)

using namespace std;

int A[501][501];
int main(){
    int w,h,n,i,x,y,x1,y2,m,res;
    while (1){
        scanf("%d %d %d",&w,&h,&n);
        if(w==0 && h==0 && n==0)break;
        m  = w*h;
        A[w][h];
        loop(i,0,w)memset(A[i],0,sizeof(A[i]));
        res=0;
        loop(i,0,n){
            scanf("%d %d %d %d",&x,&y,&x1,&y2);

        }
        if(m-res==0){
            printf("There is no empty spots.");
        }else if((m-res)==1){
            printf("There is one empty spot.");
        }else{
            printf("There are %d empty spots.",m-res);
        }
    }
    return 0;
}
