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
    in();
    out();
    vector<string> vs;
    while(1){
        string str;
        getline(cin,str);
        if(str[0]=='#')break;
        stringstream ss ;
        ss << str;
        string a;
        while(ss >> a)vs.pb(a);
    }
    vector<string> sol;
    int len = si(vs);
    forn(i,len-1){
        string a = vs[i];
        int flang = 0;
        fore(j,i+1,len-1){
            sort(all(a));
            string b = vs[j];
            sort(all(b));
            string lowerA , lowerB;
            for(auto la : a ){
                char c = ('A'<=la && la<='Z') ? (la-('Z'-'z')) : la;
                lowerA.pb(c);
            }
            for(auto lb : b){
                char c = ('A'<=lb && lb<='Z') ? (lb-('Z'-'z')) : lb;
                lowerB.pb(c);
            }
            if(lowerA== lowerB){
                    flang = 1;
                    break;
            }
        }
        if(!flang){
                sol.pb(vs[i]);
            cerr << vs[i] << endl;

        }
    }
    for(auto s : sol){
            cout << s << endl;

    }
    sort(all(sol));
    for(auto s : sol){
            cout << s << endl;

    }


    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
