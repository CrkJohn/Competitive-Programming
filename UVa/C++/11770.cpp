#include<bits/stdc++.h>
#define se second
#define fi first
#define len(str) (int)(str.length())
#define pb push_back
#define FOR(i,b) for(int i = 0 ; i<b;i++)
#define loop(i,a,b) for(int i = a ; i<b;i++)
#define SZ  1010
#define fi first
#define se second
#define LIM 10010
using namespace std;
typedef vector<string> vs;
typedef pair<int,int> ii;
//typedef map<string,vs>  G;
typedef map<string,string> father;
typedef vector<int> vi;
typedef vector<vi> G;
typedef deque<int> di;
using namespace std;

//int graph[SZ][SZ];
G graph;
int moveI[] = {-1,1,0,0};
int moveJ[] = {0,0,1,-1};
//int F,C;
int n, m, p[LIM], lo[LIM], num[LIM], dfscount, SCC;
int indeg[LIM];
bool vis[LIM];
vi AL[LIM], AL2[LIM];
stack<int> s;

void tarjan(int u){
	int v, j;
	lo[u]=num[u]= dfscount++;
	s.push(u);
	vis[u]=true;
	loop(j, 0, (int)AL[u].size()){
		v=AL[u][j];
		if (num[v]==0) tarjan(v);
		if (vis[v]) lo[u]=min(lo[u], lo[v]);
	}
	if (lo[u]==num[u]){
		//printf("SCC=%d\n", SCC);
		do{
			v=s.top(); s.pop();
			//printf("%d\n", v+1);
			vis[v]=0;
			p[v]=SCC;
		}while (u!=v);
		SCC++;
	}
}

void printAdj(int n){
    loop(i,1,n+1){
        cout << i << ": ";
        loop(j,0,AL[i].size()){
            cout << AL[i][j] << " ";
        }
        cout << '\n';
    }
}


//Inside main
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ntc,u,v;
    set<int> tm1[LIM];
    cin >> ntc;
    loop(nt,1,ntc+1){
        cin >> n >> m;
        loop(i,0,LIM){
            AL[i].clear();
            AL2[i].clear();
            tm1[i].clear();
            indeg[i] = 0;
            num[i]=lo[i]=0, vis[i]=false;
        }
        s= stack<int>();
        dfscount=1; SCC=0;
        FOR(i,m){
            cin >> u >> v;
            AL[u].pb(v);
        }
        //printAdj(n);

        loop(i, 1, n+1){
            if (num[i]==0) tarjan(i);
        }

        loop(i,1, n+1){
            loop(j, 0, (int)AL[i].size()){
                v=AL[i][j];

                if (p[i]!=p[v]){
                  tm1[p[i]].insert(p[v]);
                }

            }
        }
        loop(i, 0, SCC){
                for (set<int>::iterator it=tm1[i].begin(); it!=tm1[i].end(); it++){
                    v=(*it);
                    AL2[i].pb(v); indeg[v]+=1;
                }
        }
        int r = 0;
        loop(i,0,SCC)if(indeg[i]==0)r++;
        cout <<"Case "<<nt<<": "<< r <<'\n';

    }
    return 0;
}
