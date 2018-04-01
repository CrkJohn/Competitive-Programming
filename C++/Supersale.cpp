#include <bits/stdc++.h>
#define loop(i,a,b) for (i=a;i<b;i++)
#define MAX_N 1010
#define MAX_W 40

using namespace std;
typedef pair <int,int> ii;
int ob,Z;
int memo[MAX_N][MAX_W];
map<int,ii> objetos;


int value(int id, int w) {
  if (id == ob+1 || w == 0) return 0;
  if (memo[id][w] != -1) return memo[id][w];
  if (objetos[id].second> w)return memo[id][w] = value(id + 1, w);
  return memo[id][w] = max(value(id + 1, w), objetos[id].first + value(id + 1, w - objetos[id].second));
}

int main(){
    int cases,G,P,W,i;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&ob);
        objetos.clear();
        memset(memo, -1, sizeof(memo));
        loop(i,1,ob+1){
            scanf("%d %d",&P,&W);
            objetos[i] = make_pair(P,W);
        }
        scanf("%d",&G);
        int suma =0;
        loop(i,0,G){
            scanf("%d",&Z);
            suma+=value(0,Z);
        }
        printf("%d\n",suma);
    }
    return 0;
}
