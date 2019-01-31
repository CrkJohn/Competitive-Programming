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


int MAX_N = 100100;

string T ,P ;
int b[MAX_N],n,m;

//optimized process
void kmpPreprocess() {
	int j=-1, i=0;
	for(i=0;i<m;i++){
		if(j>=0 && P[i]==P[j]) b[i]=b[j];
		else b[i]=j;
		while(j>=0 && P[i]!=P[j]) j=b[j];
		j++;
	}
}

void kmpSearch() {
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if (j == m) {
			printf("P is found at index %d in T\n", i - j);
			j = b[j];
		}
	}
}

/* Find just the first match of the pattern in the text,
 * and return the position of the caracther after the match
 */
int kmpSearch() {
	int j=0, i;
	for(i=0;i<n;i++){
		while(j>=0 && T[i]!=P[j]) j=b[j];
		if(j+1==m){
			return i-j+1;
		}
		j++;
	}
	return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
		cout << fixed;
		cin >> P;
		T = P;
		reverse(all(P));
		T+=P;
		kmpPreprocess();


    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}



