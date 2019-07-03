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
#define cls(a,val) memset(a,val,sizeof a)
const int  INF  =  (int)1e9;

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

template <typename T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";for(auto e : v) os << e << " ";
    return os << "]";
}



void print_stack(queue<int> c) {
    cerr << "queue {";
    while (!c.empty()) {
        cerr<<c.front()<<",";
        c.pop();
    }
    cerr << "}" << endl;
}

const int MAXN = 3 * 1e5 + 15; 
int sgt[4*MAXN], a[MAXN] , b[MAXN];

int rmq(int posSgt, int l ,int r , int ql, int qr){
    if(l>qr || ql>r)return INF;
    if(ql<= l && r <=qr)return sgt[posSgt];
    int mid = (l+r)>>1;
    return min(rmq(posSgt*2,l,mid,ql,qr),rmq(posSgt*2+1,mid+1,r,ql,qr));
}


void update(int posSgt , int l, int r,int posArray, int  value){
    //cout << l << " " << r << " " << posArray <<  endl;
    if(r==l){
        //cout << "l" << l << " r " << r << endl;
        sgt[posSgt] = value;
        return;
    }
    int mid = (l+r)>>1;
    if(posArray <= mid){
        update(posSgt*2,l,mid,posArray,value);
    }else{
        update(posSgt*2+1,mid+1,r,posArray,value);
    }
    sgt[posSgt] = min(sgt[posSgt*2],sgt[posSgt*2+1]);
}


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
    while(q--){
        int n;
        cin >> n;
        a[n+1] , b[1+n] , sgt[4*n];
        forn(i,4*n)sgt[i] = INF;
        vector<queue<int>> vst(n+1);
        fore(i,1,n){
            cin >> a[i];
            vst[a[i]].push(i);
        }
        fore(i,1,n)cin >> b[i];
        fore(i,1,n){
            if(vst[i].empty())continue;
            update(1, 1, n, i, vst[i].front());
        }

        short int Oka = 1;
        fore(i,1,n){
            if(vst[b[i]].empty()){
                Oka = 0;
                break;
            }
            //print_stack(vst[b[i]]);
            int minimunPos = vst[b[i]].front();
            
            int query = rmq(1,1,n,1,b[i]);
            //cerr << "mini " << minimunPos <<  " q : " << query << " " << b[i] <<  endl;
           
            if(minimunPos > query){
                //cerr << "param q" << b[i] << endl;
                //cerr << "i : " << i << endl;
           
                Oka = 0;
                break;
            }
            vst[b[i]].pop();
            update(1, 1, n, b[i], vst[b[i]].empty() ? INF : vst[b[i]].front() );
        }
        //cerr << endl;
        cout << ((Oka)? "YES ": "NO") << endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


