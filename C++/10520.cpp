#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a ; i<b ; ++i)
#define FOR(i,b) for(int i = 0 ; i<b ; ++i)

using namespace std;
typedef long long large;
large n,dp[30][30];

large a(int i , int j){
    large v1 = 0 ,v2 = 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i>=j){
        if(i<n)loop(k,i+1,n+1)v1 = max(a(k,1)+a(k,j),v1);
        if(j>0) loop(k,1,j) v2  = max(v2,a(i,k)+a(n,k));
        return dp[i][j] = v1 + v2;
    }
    if(i<j){
        v2 =  a(i, i) + a(i + 1, j);
        loop(k,i+1,j) v2  = max(v2,a(i,k)+a(k+1,j));
        return dp[i][j] = v2;
    }
}


int main(){
    large a_n1;
    while((scanf("%lld %lld",&n,&a_n1))==2){
        //printf("%lld\n",n);
        memset(dp, -1 , sizeof dp);
        dp[n][1] = a_n1;
        printf("%lld\n",a(1,n));
    }
    return 0;
}
