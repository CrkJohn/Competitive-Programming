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




int n,m;

bool let(const int x, const int y){
	return  0<=x && x<n && 0<=y && y<m;
}

const int maxn = 123;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;




    //in();
		cin >> n >> m;
	  vector<string> vs(n);
    forn(i,n)cin >> vs[i];
    forn(i,n){
        forn(j,m){
            if(vs[i][j]!=vs[i][0]){
                cout << "NO" << endl;
                return 0;
            }
        }
        if(i>0 && vs[i][0]== vs[i-1][0]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}

