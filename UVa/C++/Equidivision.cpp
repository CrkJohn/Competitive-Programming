#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define MAX 101

using namespace std;
typedef set<int> si;

char lec[MAX*MAX];
int x[4]={1,-1,0,0};
int y[4]={0,0,-1,1};
int mat[160][160];
int vis[160][160];
si conjunto;

bool let(int i, int j, int n){
    if( 0<=i && i<n && j>=0 && j<n)return true;
    else false;
}

void FD(int a, int b, int see,int n){
    int i;
    vis[a][b] = 1;
    loop(i,0,4){
        int h = a+x[i],k=b+y[i];
        if(vis[h][k]==-1 && mat[h][k]==see && let(h,k,n)){
            FD(h,k,see,n);

        }
    }
    return;
}
bool res(int n){
    int i ,j;
    conjunto.clear();
    loop(i,0,n){
            loop(j,0,n){
                if(vis[i][j]==-1){
                    if(conjunto.count(mat[i][j]))return false;
                    conjunto.insert(mat[i][j]);
                    FD(i,j,mat[i][j],n);
                }
            }
    }
    return true;
}


int main(){
    int n,num,x,y,i,j;
    while(scanf("%d",&n)==1,n){
        getchar();
        if(n==1)puts("good");
        else{
            memset(vis,-1,sizeof vis);
            memset(mat, 0,sizeof mat);
            loop(i,0,n-1){
                gets(lec);
                stringstream ss(lec);
                loop(j,0,n)
                {
                    ss >> x >> y;
                    x--;y--;
                    mat[x][y] = i+1;
                }
            }
            if (res(n)) printf("good\n");
            else printf("wrong\n");
        }
    }
    return 0;
}
