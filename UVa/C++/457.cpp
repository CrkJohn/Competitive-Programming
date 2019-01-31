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
    in();
    out();
    int ntc;
    cin >> ntc;
    forn(nt,ntc){
				int adn[10];
				forn(i,10){
					cin >> adn[i];
				}
				int day[55][45];
				memset(day,0,sizeof day);
				day[0][19] = 1;
				fore(i,1,50){
					fore(j,1,40){
							 day[i][j] = adn[ day[i-1][j-1] + day[i-1][j] + day[i-1][j+1]];
							 int sum = day[i-1][j];
										if (sum == 0)cout << ' ';
										if(sum == 1) cout << '.';
										if(sum == 2) cout << 'x';
										if(sum == 3) cout << 'W';

					}
					cout << endl;
				}


		}
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
