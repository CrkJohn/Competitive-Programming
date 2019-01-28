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

const int maxn = 1e9 + 10;

ll descompision(ll &num){
	ll suma = 0;
	while(num){
			int n = num%10;
			suma+=(n*n);
			num/=10;
	}
	return suma;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    in();
    int ntc;
    cin >> ntc;
    for1(nt,ntc){
			ll num;cin >> num;
			ll num2 = num;
			map<ll,ll> found;
			while(!found[num] && num!=1){
//					 cerr << "before num : " << num;
					 found[num]=1;
					 num = descompision(num);
//					 cerr << " after num :  "<< num << endl;
			}
			if(num==1)cout << "Case #"<<nt<<": "<<num2<<" is a Happy number." << endl;
			else cout <<"Case #"<<nt<<": "<<num2<<" is an Unhappy number." << endl;
	  }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
