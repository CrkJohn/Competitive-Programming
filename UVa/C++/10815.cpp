
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
    in();
    out();
    vector<string> vs;
		set<string> stS;
		while(1){
			string str;
			getline(cin,str);
			if(cin.eof())break;
      stringstream ss;
      ss << str;
      string tokens;
      while(ss >> tokens){
          string sp  = "";
          int len = tokens.length();
          forn(i,len){
              if(tokens[i]>='a' && tokens[i]<='z'){
									sp.pb(tokens[i]);
              }
              else if(tokens[i]>='A' && tokens[i]<='Z'){
								sp.pb(tokens[i]-('Z' - 'z'));
              }              else{
								if(sp.length()>0){
										stS.insert(sp);
										sp = "";
								}
						}
					}
					if(sp.length()>0)stS.insert(sp);
				}
		}
		vs.assign(stS.begin(),stS.end());
		sort(all(vs));
		for(auto s : vs){
					cout << s << endl;

		}
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
