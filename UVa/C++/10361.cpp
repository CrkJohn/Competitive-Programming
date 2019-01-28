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
		int ntc;
		cin >> ntc;
		string l1,l2;
    string s2,s3,s4,s5;
    int pos1,pos2,pos3,pos4;
		string st;
		getline(cin,st);
		forn(nt,ntc){
			 getline(cin,l1);
			 getline(cin,l2);

        pos1=l1.find("<");
        pos2=l1.find(">");
        pos3=l1.find("<",pos1+1);
        pos4=l1.find(">",pos2+1);

        s2=l1.substr(pos1+1,pos2-pos1-1);
        s3=l1.substr(pos2+1,pos3-pos2-1);
        s4=l1.substr(pos3+1,pos4-pos3-1);
        s5=l1.substr(pos4+1,l1.size()-pos4-1);

        l1.erase(pos1,1);
        l1.erase(pos2-1,1);
        l1.erase(pos3-2,1);
        l1.erase(pos4-3,1);

        cout<<l1<<endl;

        pos1=l2.find("...");
        l2.erase(pos1,3);
        l2.insert(pos1,s4+s3+s2+s5);

        cout<<l2<<endl;
		}
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
