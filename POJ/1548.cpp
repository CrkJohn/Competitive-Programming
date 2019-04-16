#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define INF 1e9
#define eps 1e-9
#define PI acos(-1.0)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define for1(i,n) for(int i=1;i<=(int)(n); ++i)
#define ford(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define fore(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long large;

ostream & operator<< (ostream &out, const ii &c){
	out << "{" << c.fi << "," << c.se << "} ";
    return out;
}


int R,C;

vector< priority_queue<int,vector<int>, greater<int> > > G;


int bfs(){
    queue< ii > q;
    int vis[R][C];
    memset(vis,0,sizeof vis);
    int maxForc,c = 0;
    vis[0][0] = 1;
    int cnt  = 0;
    int maxR;
    forn(r,R){
        if(G[r].size()>0){
                maxR = G[r].top();
                G[r].pop();
                q.push({r,maxR});
                cnt++;
                //cout << ii(r,maxR) << " : ";
        }else continue;
        while(!q.empty()){
            ii u = q.front(); q.pop();
            cerr << u;
            if(G[u.fi].size()>0){
                maxR =  G[u.fi].top();
                if(maxR < u.se){
                    if(u.fi+1 < R)q.push({u.fi+1,u.se});
                    continue;
                }else{
                    G[u.fi].pop();
                    fore(i,maxR,u.se)vis[u.fi][i] = 1;
                    if(u.fi+1 < R){
                        q.push({u.fi+1,maxR});
                    }else if(u.fi == R-1){
                        cerr << "ahi" << endl;
                    }
                }
            }else{
                if(u.fi+1 < R)q.push({u.fi+1,u.se});
            }

        }
        cerr << endl;
    }
    return cnt;
}



int main(){
    in();//freopen quitar antes de un envio
    //out();//freopen quitar antes de un envio
    err();
    ios::sync_with_stdio(0);
  	cin.tie(0);
  	cout << fixed;
  	cout.precision(4);
    G.assign(26,  priority_queue<int,vector<int>, greater<int> >());
    while(1){
        int r,c;
        cin >> r >> c;
        if(r== 0 && c == 0){
            cout << bfs() << endl;
            G.assign(26,  priority_queue<int,vector<int>, greater<int> >());
            R  =  C = -1e9;
        }else if(r==-1 && c == -1){
            break;
        }else{
            R = max(R,r);
            C = max(C,c);
            r--; c--;
            G[r].push(c);
        }
    }
    cerr << "Time elapsed: ";
    cerr << 1.0 * clock() / CLOCKS_PER_SEC;
    cerr << " s.\n";
    return 0;
}


