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
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


vs res;


int solve(){
		int n = si(res);
		forn(i,n){
			string a = res[i];
			int lenA = si(res[i]);
			for(int j = 0; j<n ; j++){
          if(i==j)continue;
          string b = res[j];
          int lenB = si(b);
          if(lenB>lenA){
							string sub = b.substr(0,lenA);
							if(sub == a){
									return 0;
							}
          }
			}
		}
		return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    //in();
    //out();
    int ntc = 1;
    while(1){
				string str;
				getline(cin,str);
				if(str.length()==0)break;
				if(str[0]=='9'){
					int res2 = solve();
					res.clear();
					if(res2){
						cout <<"Set "<<ntc++<<" is immediately decodable" <<endl;
					}else{
						cout <<"Set "<<ntc++<<" is not immediately decodable" << endl;
					}
				}else{
						res.pb(str);
				}
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
