#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b; i++)


using namespace std;
typedef long long large;
const large inf =  1LL<<60;


int main(){
    freopen("423UVa.txt","r",stdin);
    int c;
    string inp; stringstream ss;
    large FDW[110][110];
    while(scanf("%d",&c)==1){
    //memset(FDW,0, sizeof FDW);
    loop(i,0,c){
        for(int j = 0; j <= i; j++){
            if(i==j) FDW[i][j] = 0;
            else{
            cin >> inp;
            if(inp == "x")FDW[i][j] = inf;
            else FDW[i][j] = atoi(inp.c_str());
            FDW[j][i] = FDW[i][j];
            }
        }
    }

    loop(i,0,c){
        loop(j,0,c){
            printf("%lld ",FDW[i][j]);
        }
        puts("");
    }
    loop(k,0,c)loop(i,0,c)loop(j,0,c) FDW[i][j] = min(FDW[i][j],FDW[i][k]+FDW[k][j]);
    large res = 0;
    loop(i,0,c)res = max(FDW[i][0],res);
    printf("%lld\n",res);
    }
    return 0;
}
