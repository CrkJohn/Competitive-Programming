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
#define out(x) freopen(#x".txt","w",stdout)
#define err() freopen("err.txt","w",stderr)
#define cls(a,val) memset(a,val,sizeof a)
#define INF  1e9;
#define len(a) ((int)a.size())



using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef double ld;

template <typename T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";for(auto e : v) os << e << " ";
    return os << "]";
}

const double PI = acos(-1); 
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }


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
    int q;
    cin >> q;
    string s,t,p;
        
    getline(cin,s);
    forn(qq,q){
        getline(cin,s);
        getline(cin,t);
        getline(cin,p);
        int memo[26];
        cls(memo,0);
        forn(i,len(p)){
            memo[p[i]-'a']++;
        }
        int j = 0;
        int ok = 1;
        string ans = "";
        //cerr << s   <<" " << t << " " << p << endl;
        forn(i,len(t)){
            if(len(s)==j){
                if(memo[t[i]-'a']==0){
                    ok  = 0;
                    break;
                }
                memo[t[i]-'a']--;
            }else{
                if(s[j]==t[i]){
                    j++;
                    ans+=s[j];
                }else if(s[j]!=t[i] && memo[t[i]-'a']==0)ok = 0 ;
                else if(s[j]!=t[i] && memo[t[i]-'a']>0){
                    memo[t[i]-'a']--;
                }
            }
        }
        cout << ( ok && j ==len(s) ? "YES" : "NO"  ) << endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


