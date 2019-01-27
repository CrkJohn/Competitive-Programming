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
typedef vector<string> vs;
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
    int n,i;
    string s1,s2;
    while(1){
        cin>>n;
        if(n==0)break;
        vs v1, v2;
				getline(cin,s1);
        forn(i,n){
            getline(cin,s1);
            getline(cin,s2);
            v1.pb(s1);
            v2.pb(s2);
        }
        getline(cin,s1);
        i=0;
        while(i!=v1.size()){
            n=s1.find(v1[ax]);
            if(n!=-1){
                s1.erase(n,v1[i].size());
                s1.insert(n,v2[i]);
            }else i++;
        }
        cout<<s1<<endl;
    }
    return 0;
}
