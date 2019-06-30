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
    int n;
    cin >> n;
    string  a;
    cin >> a;
    vvi voc;
    voc.assign(27,vi());
    forn(i,n){
        voc[ a[i]- 'a' ].pb(i);
        //cout << a[i]-'a'  << " "  << a[i] << " " << i << endl;
    }
    /*
    int i = 0;
    forn(i,26){
        char z = i+'a';
        cout << z << " ";
        for(int t : voc[i]){
            cout << t << " ";
        }
        cout << endl;
    }
    cout << endl;
     */
    int m;
    cin >> m;
    forn(i,m){
        string b;
        cin >> b;
        //cout << b << endl;
        int vocabulary[26];
        memset(vocabulary, 0 , sizeof vocabulary);
        int res = -1e9;
       
        for(auto c  : b){
        //    cout <<" kha c " <<  c   << " " <<  voc[c - 'a'].size() << endl;
            res = max(voc[c - 'a'][vocabulary[c-'a']++],res);
        }
        cout << res+1 << endl;
    }
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;

} 


