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
typedef  pair<int,string>  pis;
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
    /*
    in();
    err();
    out();
    */
    vector<string> vs;
    while(1){
        string str;
        getline(cin,str);
        if(str[0]=='#')break;
        stringstream ss ;
        ss << str;
        string a;
//        cerr << str << endl;
        while(ss >> a)vs.pb(a);
    }
    set<string> sol;
    int len = si(vs);
    forn(i,len){
        string a = vs[i];
//        cerr << " a : " << a << endl;
        int flang = 1;
        forn(j,len){
						if(i==j)continue;
            string b = vs[j];
            string lowerA , lowerB;
            for(auto la : a ){
                char c = ('A'<=la && la<='Z') ? (la-('Z'-'z')) : la;
                lowerA.pb(c);
            }
            for(auto lb : b){
                char c = ('A'<=lb && lb<='Z') ? (lb-('Z'-'z')) : lb;
                lowerB.pb(c);
            }
            sort(all(lowerB));
            sort(all(lowerA));
						if(a=="BARRY")cerr << "lower a : " << lowerA << " lower b : " << lowerB << " \n b : " << b << endl;
            if(lowerA== lowerB){
								if(lowerA=="barry"){
									 cerr << a << " " << b << endl;
								}
									flang = 0;
									break;
            }
        }
        if(flang){
						sol.insert(vs[i]);
        }
    }
    for(auto s : sol){
					cout << s << endl;
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
