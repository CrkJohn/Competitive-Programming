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
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    map<char,char> cast;
    err();
    int  cont = 0 , valMap = 2;
    forn(i,26){
    	 if(i==25 || i==16)continue;
			 cont++;cast[i+'A'] = valMap+'0';
			 if(cont==3){
					valMap++;cont = 0;
			 }
    }
    //in();
    //out();
    int ntc;
    cin >> ntc;
    int f = 0;
    for1(nt,ntc){
			int n; cin >> n;
			string str;
			getline(cin,str);
			vector<string> vs;
			map<string,int> dupli;
			int isDuplicate = 0;
			forn(i,n){
					getline(cin,str);
					string del = "";
					for(auto  s : str){
							if('A'<= s && s<='Z'){
									del.pb(cast[s]);
							}
							if('0'<= s && s<='9')del.pb(s);
					}
//					cerr << str << " " << del << endl;
					if(dupli.find(del)==dupli.end()){
						dupli[del] = 1;
					}else{
						isDuplicate = 1;
						dupli[del]++;
					}
					vs.pb(del);
			}
			if(f) cout << endl;
			f = 1;
			if(!isDuplicate){
					cout << "No duplicates."<< endl;
			}else{
				vector< pair<string,int> > solve;
				for(auto s : dupli){
					if(s.se>1)solve.pb( {s.fi,s.se});
				}
				sort(all(solve));
				for(auto t : solve)	cout << t.fi.substr(0,3) << "-" << t.fi.substr(3,4) << " " << t.se << endl;

			}



    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
