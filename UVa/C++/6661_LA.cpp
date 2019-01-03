#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;++i)
using namespace std;

int k,s,n,cont,ar[22];
int f(int S,int E,int i){
    //printf("%d %d %d\n",S,E,i);
    if (E == k && S==s){return   cont++;}
    if ((S>s) || (S<s && E==k) || i>n || E>k)  return 0;
    f(S+ar[i],E+1,i+1);f(S,E,i+1);
}
int main(){
    int i;
    while(1){
        scanf("%d %d %d",&n,&k,&s);
        if(n+k+s==0)break;
        loop(i,1,n+1)ar[i]=i;
        //loop(i,1,n+1)printf("%d ",ar[i]);
        cont=0;
        f(0,0,1);
        printf("%d\n",cont);
    }
    return 0;
}
