#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a; i<b;++i)
using namespace std;

int arr[16];

bool ver(int n){
    int sum=0,i;
    loop(i,0,n)sum+=arr[i];
    if(sum==0){return true;}
    else{ return false;}
}


void change(int n){
    int i;
    int a = arr[0];
    loop(i,0,n-1)arr[i] = abs(arr[i]-arr[i+1]);
    arr[n-1] = abs(arr[n-1]-a);
}

bool det(int n){
    int i;
    if(ver(n))return true;
    loop(i,0,1001){
        change(n);
        if(ver(n))return true ;
    }
    return false;
}

int main(){
    int cases,i,n;
    scanf("%d",&cases);
    while (cases--){
        memset(arr,0,sizeof(arr));
        scanf("%d",&n);
        arr[n];
        loop (i,0,n) scanf("%d",&arr[i]);
        (det(n)) ?  printf("ZERO\n") : printf("LOOP\n");
    }
    return 0;
}
