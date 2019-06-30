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
    map<int,int> goodArray;
    goodArray[4] = 1 , goodArray[8] = 2 , goodArray[15] = 3;
    goodArray[16] = 4 , goodArray[23] = 5, goodArray[42] = 6;
    int cnt[] = {0,0,0,0,0,0,0};
    forn(i,n){
        int num; cin >> num;
        int value = goodArray[num];
        if(value){
            if(value == 1)cnt[value]++;
            else if(cnt[value-1]>0){
                cnt[value]++;
                cnt[value-1]--;
            }
        }
    }
    cout << n - cnt[6]*6 << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;

} 


