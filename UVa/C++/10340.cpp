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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
		string str;
		in();
		out();
		while(1){
				getline(cin,str);
				if(cin.eof())break;
				stringstream ss(str);
				string str1,str2;
				ss >> str1 >> str2;
//				cout << str1 << " " << str2 << endl;
				int i = 0, j = 0 , n  = str1.length() , m = str2.length();
				bool f,result = true;
				while(i<n){
						f = false;
						while(j < m){
							 if(str1[i]==str2[j]){
//								  cerr << "s1 : " << str1[i] <<  " s2: " << str2[j] << endl;
//								  cerr << " i : " << i << " j : " << j << endl;
									 f = true;
									 j++;
									 break;
							 }
							 j++;
						}
						i++;
						if(!f)result = false;
				}
//				cerr << endl;
        cout << ((result) ? "Yes" : "No") << endl;
		}
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
