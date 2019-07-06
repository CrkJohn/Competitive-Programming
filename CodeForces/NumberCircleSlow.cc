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


bool fd;
const int maxn = 1e5+10;
int lon,arr[maxn];

template <typename T> ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";for(auto e : v) os << e << " ";
    return os << "]";
}

void  back(int ind, vi vis,vi final){
    
    if(fd)return;
    if(ind == lon-1){
        if (final[0]+final[lon-2] > final[lon-1] and final[lon-1]+final[1]>final[0]){       
            fd = 1;
            cout << "YES" << endl;
            forn(i,lon-1)cout << final[i] << " "; 
            cout << final[lon-1] << endl;
        }
        return;
    }
    else{
        fore(i,ind,lon-1){
            int num = final[ind];
            int prev = final[ind-1];
            forn(k,lon){
                if(!vis[k] && prev+arr[k]>num){
                    final[ind+1] = arr[k];
                    vis[k] =1;
                    back(ind+1,vis,final);
                    vis[k] = 0;
                }
            }   
                   
        }
            
    }        
        
}

int  main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    in();
    err();
#endif
 
    cin >> lon;
    arr[lon];
    forn(i,lon) cin >> arr[i];
    vi vis,final;
    vis.assign(lon+1,0);
    final.assign(lon+1,0);
    fd = 0;
    forn(i,lon){
        fore(j,i+1,lon-1){
            final[0] = arr[i];
            vis[i]  = 1;
            vis[j]  = 1;
            final[1] = arr[j];
            back(1,vis,final);
            //cerr << "sol " << endl;
            vis[i]  = 0;
            vis[j]  = 0;
            if(fd) break;
        }
        if(fd)break;
    }
    if (!fd)cout << "NO" << endl;

}
    