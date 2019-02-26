#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)
#define si(a) ((int)a.size())

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pi64;
typedef double ld;

ostream & operator<< (ostream &out, const pii &c){
	out << "x =" << c.fi << ",y = " << c.se << ";\n";
    return out;
}



int maxn = 30;
vector< string > g;

const int dx[] = { 1  , -1 , 0 ,0 };
const int dy[] = { 0  , 0  , -1 ,1 };


typedef pair<int, pii> node;

int w , h ;

int let(const int &i  , const int &j){
	 return 0<= i && i<h && 0<=j && j<w;
}




int dijkstra(const pii &src, const pii &tgt){
	priority_queue<node,vector<node>,greater<node> > pq;
	int res = 0;
	int vis[maxn][maxn];
	forn(i,maxn)forn(j,maxn)vis[i][j] = 1e9;
	vis[src.fi][src.se] = 0;
	pq.push(node(0,src));
	while(!pq.empty()){
			node nd = pq.top(); pq.pop();

			int d= nd.fi;pii u=nd.se;
			if(u.fi == tgt.fi && u.se == tgt.se)break;
			if (d>vis[u.fi][u.se]) continue;
			forn(i,4){
				int h = u.fi + dx[i] , k = u.se + dy[i];
				if(!let(h,k))continue;
				if(g[h][k]=='X'  )continue;
				//cerr << g[h][k] << endl;
				int w = g[h][k]  - '0';
				if (vis[u.fi][u.se] + w < vis[h][k]){
					vis[h][k]= vis[u.fi][u.se] + w;
					pq.push(node(vis[h][k], pii(h,k)));
				}
		}

	}
	/*
	forn(i,h){
		forn(j,w){
			cerr << vis[i][j]<< " " ;
		}
		cerr << endl;
	}
	*/
	return vis[tgt.fi][tgt.se];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    //in();
    string str;
    while(cin >> w >> h ,w+h!=0){
			getline(cin,str);
			//g.assign(h+1,vector<string>());
			g.resize(h+1);
			pii src, tgt;
			forn(i,h){
					getline(cin,g[i]);
					forn(j,w){
							char c = g[i][j];
							if(c  == 'S') src = pii(i,j);
							if(c  == 'D'){
								tgt = pii(i,j);
								g[i][j] = '0';
							}
					}
			}
			//cout << src << tgt<< endl;


			getline(cin,str);
			int res = dijkstra(src ,tgt);
			cout << res << endl;

    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
