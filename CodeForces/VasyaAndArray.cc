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

struct query{
    int t  , i , j ;
    query(int T, int I ,int J){
        t = T;
        i = I;
        j = J;
    }
    bool operator < ( const query other)const{
        return i < other.i && j < other.j;
    }
};

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
    int siA , q;
    cin >> siA  >> q;
    int p = 0;
    //if(siA==1000 && q ==904) p = 1;
    int zeros = 0;
    vector<query> qs;
    forn(ii,q){
        int ty , i , j;
        cin >> ty >> i >> j ;
        qs.pb(query(ty,i,j));
        if(p){
            cout << i << " " << j << endl;
        }
        if(ty ==0)zeros++;
    }  
    if(p) cout << zeros << endl;
    /*
    sort(all(qs));
    for(auto t : qs){
        cout << t.t << "("  << t.i << "," << t.j << ")" <<  endl;
    }*/
    int isValid = true;
    query  fs = qs[0];
    int iter = 0;
    int res[10002];
    fore(i,1,siA)res[i] =1;

    fore(x,fs.i,fs.j){
        int tmp = 1;
        if(fs.t == 0){
            tmp = fs.j-fs.i;
        //    cout << " tmp " << tmp << endl;
        }    
        res[x] = tmp + ( fs.t == 1  ? 1 : -1) *(iter++); 
    }
    /*fore(a,1,siA)cout << res[a] << " ";
    cout << endl;
     */
    fore(i,1,q-1){
        query qr = qs[i];
        //cout << qr.i << " " << qr.j << " "  << qr.t << endl; 
        if(qr.t!=fs.t && qr.i < fs.j )isValid = 0;
        int initial = res[qr.i];
        int inter = 0;
        fore(j, qr.i, qr.j){
            res[j] = initial + ((qr.t == 0 ) ? inter-- : inter++);
        }
        fs = qr;     
    }

    if(isValid){
        cout << "YES" << endl;
        fore(i,1,siA-1){
            cout << res[i] << " ";
        }
        cout << res[siA-1] << endl;
    }else{
        cout << "NO" << endl;
    } 

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
   
    return 0;

} 


