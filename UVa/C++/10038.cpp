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
#define next(i,n) ((int)i%(int)n)

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    in();
    out();
		while(1){
				int n;
				cin >> n;
				if(cin.eof())break;
				int arr[n];
				forn(i,n)cin>> arr[i];
				int absR[n];
				memset(absR,0,sizeof absR);
				short int rep = 0;
				forn(i,n-1){
						int r = abs(arr[i]-arr[i+1]);
						cerr << "before if : r " << r << endl;
						if(r> n-1 || absR[r]!=0){
								rep = 1;
								cerr << r << endl;
								break;
						}else{
							  absR[r] = 1;
						}
				}
				if(rep){
						cout << "Not jolly" <<  endl;
				}else{
						cout << "Jolly" << endl;
				}
		}
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
