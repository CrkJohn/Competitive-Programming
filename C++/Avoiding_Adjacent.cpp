#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)

using namespace std;


int main(){
    int len,i;
    long L,Ci=0;
    scanf("%d",&len);
    vector<int> vi(len);
    loop(i,0,len){scanf("%d",&L);Ci=Ci+L;}
    loop(i,0,Ci)scanf("%d",&vi[i]);
    printf("%d",Ci);


    return 0;
}
