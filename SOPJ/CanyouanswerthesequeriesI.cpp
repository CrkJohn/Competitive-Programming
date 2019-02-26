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
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pi64;
typedef double ld;

ostream & operator<< (ostream &out, const pii &c){
	out << "x =" << c.fi << ",y = " << c.se << ";";
    return out;
}


const int maxn = 10000;

int sgt[4*maxn];
int input[maxn];


int op(const int &n, const int &m){
	return n+m;
}

void build(int l , int  h , int i){
	//cout << " l : " << l << " h : " << h << " i : " << i << endl;
	if(l == h){
			sgt[i] = input[l];
			return;
	}
	int mid = (l+h)/2;
	build(l,mid,i*2+1);
	build(mid+1,h,i*2+2);
	sgt[i] = op(sgt[2*i+1], sgt[2*i+2]);
}


int rmq(int l , int h){


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n;
    in();
    cin >> n;
    input[n];
    forn(i,n){
    	cin >> input[i];
    }
    build(0,n-1,0);
    forn(i,2*n){
			cout << sgt[i]  <<" ";
    }
    cout << endl;
		int q;
		cin >> q;
		forn(query,q){
			int  x,y;
			cin >> x>> y;
      x--; y--;
			cout << rmq(x,y) << endl;
		}

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
