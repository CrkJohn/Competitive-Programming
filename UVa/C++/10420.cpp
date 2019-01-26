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
    //   in();
    //out();
    int ntc;
    string str;

    while(cin >> ntc){
        string str,a;
        getline(cin,str);
        map<string,int> mapi;
        vector<string> lits;
        forn(i,ntc){
            getline(cin,str);
             stringstream ss;
            ss << str;
            ss >> a;
            if(!mapi[a]){
                mapi[a] = 1;
                lits.pb(a);

            }else{
                mapi[a]++;
            }
        }
        sort(all(lits));
        for(auto stri  : lits){
            cout <<  stri << " " << mapi[stri] << endl;
        }
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
