#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)


using namespace std;
typedef long long large;

bool cmp(int a,int b){
    return a>b;
}
int main(){
    large nodos;
    int cases,i;
    scanf("%d",&cases);
    int arr[cases];
    loop(i,0,cases){scanf("%d",&arr[i]);}
    sort(arr,arr+cases,cmp);
    nodos=arr[0];
    large anterior = arr[0];
    loop(i,1,cases){
        nodos = nodos+ (anterior*arr[i]);
        anterior = anterior*arr[i];
    }
    printf("%lld\n",nodos+1);



    return 0;
}
