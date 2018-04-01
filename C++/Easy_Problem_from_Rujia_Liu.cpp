#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)

using namespace std;
typedef vector<int> vi;

int main(){
    int sz,q,n,k,v,i,j;
    vector<vi> matriz;
    while ((scanf("%d %d",&sz,&q))== 2){
        matriz.clear();
        loop(i,0,1000005)matriz.push_back(vi());
        loop(j,0,sz){
            scanf("%d",&n);
            matriz[n].push_back(j+1);
        }
        loop(i,0,q){
            scanf("%d %d",&k,&v);
            if (matriz[v].size()<k){
               printf("0\n");
            }else{
                 printf("%d\n",matriz[v][k-1]);
            }
        }
    }
    return 0;
}
