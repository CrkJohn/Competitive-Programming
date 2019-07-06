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
#define INF  1e9;



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

struct sgt{
    int candy,sum;
    
};

const int maxn = 1e5 + 10;

int arr[maxn];
sgt segm[4* maxn];

void csgt(int p , int l , int r){
    if( l == r){
        segm[p].sum = arr[l];
        segm[p].candy = 0;
        return;
    }
    int mid = (l+r)>>1;
    csgt(p<<1,l,mid);
    csgt(p<<1|1,mid+1,r);
    segm[p].sum = (segm[p<<1].sum%10 + segm[p<<1|1].sum%10);
    segm[p].candy = (segm[p].sum >= 10 ? 1 : 0) +  segm[p<<1].candy + segm[p<<1|1].candy;
}

sgt query(int p,int l,int r,int ql, int qr){
    if(l>qr || ql>r)return {0,0};
    if(ql<= l && r <=qr)return segm[p];
    int mid  = (l+r)>>1;
    sgt  a = query(p<<1,l, mid, ql,qr);
    sgt  b = query(p<<1|1,mid+1,r,ql,qr);
    sgt res;  res.sum = a.sum%10  + b.sum%10;
    res.candy = (res.sum >= 10 ? 1 : 0) +  a.candy + b.candy;
    return res;
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
    int n;
    cin >> n;
    arr[n+1];
    fore(i,1,n) cin >> arr[i];
    csgt(1,1,n);
    int q; 
    cin >> q;
    forn(qry,q){
        int ql,qr;
        cin >> ql >> qr;
        cout << query(1,1,n,ql,qr).candy << endl;
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
} 


