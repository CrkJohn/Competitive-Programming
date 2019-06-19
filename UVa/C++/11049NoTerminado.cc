#include<bits/stdc++.h>
#define fi first
#define se second


using namespace std;


typedef pair<int,int> pii;

int g[7][7];    
int vis[7][7];

int bfs(pii src,pii tgt){
    int pa[26];



}



int main(){
    freopen("in.txt","r",stdin);
    pii src , tgt;
    int iLeft , jLeft, iRigth , jRigth;
    while(1){
        cin >> src.fi  >> src.se;
        if(src.fi == 0 && src.se ==0)break;
        memset(g,0,sizeof g);
        cin >> tgt.fi  >> tgt.se;
        for (int k = 0; k < 3; k++){
            cin >>  iLeft >>  jLeft >>  iRigth >> jRigth;
            for (int i = iLeft; i <= iRigth; i++){
                for (int j = jLeft; j <= jRigth; j++){
                     g[i][j] = -1;
                }   
            }
        }
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                cout << g[i][j] << ' '; 
            }
            cout << endl;
        }
        
    }
    return 0;
}