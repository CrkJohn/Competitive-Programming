#include<bits/stdc++.h>
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define FOR(i,b) for(int i = 0 ; i< b; i++)
#define loop(i,a,b) for(int i = a ; i< b; i++)
#define fors(i,a,b,s) for(int i=a;i<b;i=i+s)
#define pb push_back
#define fi first
#define se second

using namespace std;

/*
	Author : John David Ibanez
	Time:

*/

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<double,int> di;
typedef vector<di> vid;
typedef vector<vid> vvid;

vvid g;


const double EPS = 1e-9;
const int MAX_N = 1100;

int dis[MAX_N];


typedef pair<double,double> dd;


ostream & operator << (ostream &out, const dd &c){
		out << "(" << c.fi << "," << c.se << ")\n";
    return out;
}




int bfs(const double &max_d,const int &n){
		queue<int> q;
		q.push(0);
		FOR(i,n)dis[i] = -1;
		dis[0] = 0;
		while (!q.empty()){
			int u = q.front(); q.pop();
			if(u==1)return dis[u]- 1;
			//cerr << "u:" << u <<  endl;
			loop(j, 0, (int)g[u].size()){
				di v=g[u][j];
			//cerr << "d:" << v.fi << " v:" << v.se << endl;
				if (v.fi<max_d && dis[v.se] == -1){
					dis[v.se]= dis[u] + 1;
					q.push(v.se);
				}
		}
	}
	return -1;
}

int main(){
	//lec();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
  cout << fixed;
  cout.precision(5);
	double v,m;
	while(cin >> v >> m,m+v!=0.0){
				vector< pair<double,double> > pts;
				dd  src, tgt;
				cin >> src.fi >> src.se;
				cin >> tgt.fi >> tgt.se;
        pts.pb(src);pts.pb(tgt);
				string str;
				getline(cin,str);
				while(getline(cin,str), str != ""){
						stringstream ss;
						ss << str;
            dd p;
            ss >> p.fi >> p.se;
            ss.clear();
            pts.pb(p);
				}
				/*cerr << endl;
				FOR(i,pts.size()){
					cerr << pts[i].fi << " " << pts[i].se  << endl;
				}**/
				int lon = pts.size();
        g.assign(lon,vid());
        FOR(i,lon){
						loop(j,i+1,lon){
								dd  pta = pts[i];
								dd  ptb = pts[j];
                double V = sqrt(pow(pta.fi-ptb.fi,2) + pow(pta.se-ptb.se,2));
                g[i].pb(di(V,j));
                g[j].pb(di(V,i));
					 }
        }
        double d = v*m*60.0;
				int r = bfs(d,lon);
				if(r !=-1){
						cout << "Yes, visiting "<<r<<" other holes.\n";
				}else{
						cout << "No." << endl;
				}
	}
	return 0;
}



