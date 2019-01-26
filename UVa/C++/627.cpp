#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define rev(i,a,b) for(int i = a; i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define INF 1e9
#define eps 1e-9
#define PI acos(-1.0)
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long large;

ostream & operator << (ostream &out, const ii &c){
		out << "u :  " << c.fi << " ->  v : " << c.se << ";";
    return out;
}


double DEG_to_RAD(double d) { return d * PI / 180.0;}
double RAD_to_DEG(double r) { return r * 180.0 / PI;}


const int maxn = 301;


void bfs(const int &src, const int &tgt, const vvi &g){
  queue<int> q;
  q.push(src);
  int p[maxn];
  FOR(i,maxn)p[i] = -1;
  p[src] = src;
  while(!q.empty()){
			int u  = q.front();q.pop();
//			cerr << " u : " << u << "v  : ";
			int lon = g[u].size();
			FOR(i,lon){
         int v = g[u][i];
//         cerr << v << " ";
         if(p[v]==-1){
							p[v] = u;
							q.push(v);
         }
			}
			cerr << endl;
  }
  if(p[tgt]==-1){
			cout << "connection impossible\n";
			return;
  }
   stack<int> reversed;
	 int n = tgt;
	 while (n != src){
				reversed.push(n);
				n = p[n];
		}
		cout << src;
		while (!reversed.empty()){
					int top = reversed.top(); reversed.pop();
					cout << ' ' << top;
		}
		cout << '\n';
}


int main(){
//	lec();
	ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(4);
	stringstream ss;
	string line;
	vvi g;
	char c;
	int  f = 0;
	while(1){
			ss.clear();
			int nLines,q;cin >> nLines;
			if(cin.eof())break;
			if(f)cout << "-----\n";
			g.assign(nLines+1,vi());
			FOR(i,nLines){
          int u,v;cin >> u;
					getline(cin,line);
          stringstream ss(line);
          cerr << "u : " << u << " v : " ;
          while(ss >> c >> v){
							cerr <<v <<" ";
							g[u].pb(v);
          }
          cerr << endl;
			}
			cin >> q;
/*
			FOR(i,nLines){
					cerr << "u : " << i << " v : ";
					for(int v : g[i]){
							cerr << v << " ";
					}
					cerr << endl;
			}

*/
			if(!f)cout << "-----\n";
			f = 1;
			FOR(query,q){
          int src,tgt;
          cin >> src >> tgt;
          bfs(src,tgt,g);
			}
	}
	return 0;
}
