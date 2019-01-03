#include<bits/stdc++.h>

using namespace std;


int main(){
    int cases,x,y,dx,dy;
    while(1){
        scanf("%d",&cases);
        if (!cases)break;
        scanf("%d%d",&x,&y);
        for  (int i= 0 ; i<cases;i++){
            scanf("%d%d",&dx,&dy);

            //printf("%d %d %d %d\n",x,y,r,rd);
            if(r>0 && rd >0){
                puts("NE");
            }else if(r<0 && rd>0){
                puts("N0");
            }else if(r<0 && rd<0){
                puts("SO");;
            }else if(r==0 || rd==0){
                puts("divisa");
            }else{
                puts("SE");
            }
        }
    }
    return 0;
}
