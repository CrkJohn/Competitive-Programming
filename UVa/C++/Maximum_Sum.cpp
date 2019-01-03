#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a ; i<b;i++)

using namespace std;

int main(){
    int A[101][101];
    int N,i,j,k,l;
    int res = -127*100*100;
    scanf("%d",&N);
    loop(i,0,N){
        loop(j,0,N){
            scanf("%d",&A[i][j]);
            if (i>0){ A[i][j] += A[i-1][j];}
            if (j>0) {A[i][j] += A[i][j-1];}
            if (i>0 && j>0) {A[i][j] -= A[i-1][j-1];}
        }
    }
    loop(i,0,N){
        loop(j,0,N){
            loop(k,i,N){
                loop(l,j,N){
                    int subRect  = A[k][l];
                    if (i>0) subRect -= A[i-1][l];
                    if (j>0) subRect -= A[k][j-1];
                    if (i>0 && j>0) subRect += A[i-1][j-1];
                    res = max(res,subRect);
                }
            }
        }
    }
    printf("%d\n",res);

    return 0;
}
