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

struct team {
    string  name;
    int pt, win, lose, tie, score, invscore;
    void init() {
        pt = win = lose = tie = 0;
        score = invscore = 0;
    }
    void record(int a, int b) {
        if(a > b)   win++, pt += 3;
        else if(a < b)  lose++;
        else    tie++, pt++;
        score += a, invscore += b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
		cout << fixed;
		in();
		//err();
		int ntc;
		string str;
		cin >> ntc;
		getline(cin,str);
		cout << ntc << endl;
		forn(nt,ntc){
			map<string,int> cast;
			string nameTournet;
			getline(cin,nameTournet);

			int amountTeams;
			cin >> amountTeams;
			vector<team> teams(amountTeams);
			forn(i,amountTeams){
				cin >> teams[i].name;
				cast[teams[i].name] = i;
			}
			int games; cin >> games;
			forn(g,games){
				//Brazil#2@1#Scotland
				cin >> str;
				int num1 = str.find('#') , arroba = str.find('@',num1) , num2  = str.find('#',arroba);
        stringstream ss(str.substr(num1+1,arroba-num1 -1 ));
        ll goalsOne , goalsTwo;
        ss >> goalsOne;ss.clear();
        stringstream ss2(str.substr(arroba+1,num2-arroba -1));
        ss2 >> goalsTwo;
        string name1 = str.substr(0,num1) , name2 = str.substr(num2+1,str.length());
        cout << goalsOne << " " << goalsTwo <<  endl;
        cerr << name1 << " " << name2 << endl;


    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
