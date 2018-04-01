#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
using namespace std;
int rk[100100],padre[100100];
void c_set(int n){
    int i;
    rk[n+1];
    padre[n+1];
    loop(i,0,n+1){
        padre[i]=i;
        rk[i] = 0;
    }
}

int fd(int x){
    if(x!=padre[x])padre[x]=fd(padre[x]);
    return padre[x];
}
void UFind(int x , int y){
    int xRaiz = fd(x);
    int yRaiz = fd(y);
    if (xRaiz == yRaiz) return;
    if (rk[xRaiz] < rk[yRaiz])padre[xRaiz] = yRaiz;
    else if(rk[xRaiz] > rk[yRaiz])padre[yRaiz] = xRaiz;
    else{
            padre[yRaiz] = xRaiz;
            rk[xRaiz]++;
        }
}
int main(){
    int cases,x,y,N,i;
    scanf("%d",&cases);
    loop(i,0,cases){
        //printf("aca estoy leyendo\n");
        scanf("%d",&N);
        //printf("%d\n",N);
        getchar();
        int correct = 0,incorrect=0;
        char lec[7];
        char L;
        c_set(N);
        while (gets(lec) && sscanf(lec,"%c %d %d",&L,&x,&y)==3){
            if (L=='c')UFind(x,y);
            else if(L=='q'){
                (fd(x)==fd(y)) ? correct++ : incorrect++;
            }
        }
        //loop(i,0,N)printf("%d ",padre[i]);
        //puts("");
        printf("%d,%d\n",correct,incorrect);
        if(i+1<cases)puts("");
    }
    return 0;
}
