#include<bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define  mp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> ii;
typedef map<ii,int> mp;
mp XY;
void llenar(int a,int b){
    XY.erase(mp(a,b));
    int xi[4] = {-1,1,0,0};
    int yi[4] = {0,0,1,-1};
    int i;
    loop(i,0,4){
        int v = XY[mp(a+xi[i],b+yi[i])];
        if (v==0 || v<=3){
            XY[mp(a+xi[i],b+yi[i])]+=1;
        }else if(v==4){
            llenar(a+xi[i],b+yi[i]);
        }
    }
}
int main(){
    int Q,a,b,i;
    scanf("%d",&Q);
    loop(i,0,Q){
        scanf("%d%d",&a,&b);
        int r = XY[mp(a,b)];
        if (r==0 || r<=3){
            XY[mp(a,b)]+=1;
        }else if(r==4){
            llenar(a,b);
        }
        printf("%d\n",XY.size());
    }
    return 0;
}
