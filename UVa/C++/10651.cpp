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
#define pb push_back
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
	out << "x =" << c.fi << ",y = " << c.se << ";";
    return out;
}

int MIN = 1e9;

void solve(string str , int cnt){
    if(cnt < MIN){
        MIN = cnt;
    }
    forn(i,si(str)){
        if(str.substr(i,3)=="-oo"){
            string nw = str.substr(0,i)  + "o--"  + str.substr(i+3,si(str)-i+3);
            solve(nw,cnt-1);
        }

        if(str.substr(i,3)=="oo-"){
            string nw = str.substr(0,i)  + "--o"  + str.substr(i+3,si(str)-i+3);
            solve(nw,cnt-1);
        }
    }

}


int main() {
    //in();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int ntc;
    cin >> ntc;
    forn(c,ntc){
        string str;
        cin >> str;
        int ntc = count(all(str),'o');
        MIN = 1e9;
        solve(str,ntc);
        cout << MIN  << endl;
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
