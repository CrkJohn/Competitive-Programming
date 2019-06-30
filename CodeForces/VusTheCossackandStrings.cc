#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define len(a) ((int)a.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)


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

set<string> st;
int n,k;
   
int sol = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;

#ifdef LOCAL
    in();
    err();
#endif
    string a,b;
    cin >> a >> b;
    int cntb = 0, cnta = 0;
    forn(i,len(b)){
        if(b[i]== '1')cntb++;
        if(a[i]== '1')cnta++;
    }
    cerr << "String a " << a << " Stringb " << b << endl;
    cerr << "countb " <<  cntb << " Count a " << cnta <<endl;
    int ans = 0;
    if(cntb%2 == cnta%2 )ans++;
    fore(i,1,len(a)-len(b)){
        //cerr << " a "<< a[i-1] <<" "<< a[len(b)+i-1] << endl;
        cnta  +=  ((a[len(b)+i-1]-'0')-(a[i-1] == '1'));
        if(cntb%2 == cnta%2 )ans++;
        //cerr <<"i :" << i << " " <<  a.substr(i,len(b)) <<" " << cnta <<  endl;
    }  
    cout << ans  << endl;
    



    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;

} 


