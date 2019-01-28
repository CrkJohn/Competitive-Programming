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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
		int n;
		//in();
		//out();
		while(1){
				cin >> n;if(n==0)break;
				int fst = INT_MAX;
				vi totalSpace;
				string str;getline(cin,str);
				forn(lec,n){
					getline(cin,str);
					int i = str.find(' ');
					int j  = i;
					while(str[i++]!='X');
					i--;
					cerr << str << endl;
					cerr << " i: " <<  i << " j : " << j <<endl;
					if(j==-1){ i = j = 0;}
					totalSpace.pb(i-j);
					cerr << i-j << endl;
					fst = min(fst,i-j);
        }
        int spaceB = 0;
        for(auto B: totalSpace){
           spaceB += (B-fst);
        }
        cout << spaceB << endl;
		}
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
