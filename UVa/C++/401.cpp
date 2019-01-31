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
		map<char,char> m;
		m['A'] = 'A';
			m['B'] = ' ';
			m['C'] = ' ';
			m['D'] = ' ';
			m['E'] = '3';
			m['F'] = ' ';
			m['G'] = ' ';
			m['H'] = 'H';
			m['I'] = 'I';
			m['J'] = 'L';
			m['K'] = ' ';
			m['L'] = 'J';
			m['M'] = 'M';
			m['N'] = ' ';
			m['O'] = 'O';
			m['P'] = ' ';
			m['Q'] = ' ';
			m['R'] = ' ';
			m['S'] = '2';
			m['T'] = 'T';
			m['U'] = 'U';
			m['V'] = 'V';
			m['W'] = 'W';
			m['X'] = 'X';
			m['Y'] = 'Y';
			m['Z'] = '5';
			m['1'] = '1';
			m['2'] = 'S';
			m['3'] = 'E';
			m['4'] = ' ';
			m['5'] = 'Z';
			m['6'] = ' ';
			m['7'] = ' ';
			m['8'] = '8';
			m['9'] = ' ';
		in();
		out();
		int f = 0;
		while(1){
			string str;
			getline(cin,str);
			if(cin.eof())break;
			string result = "";
			f = 1;
			bool isPalindrome = true , isMirrored = true;

			for(auto c : str){
					if(m.find(c)!=m.end()){
						result.pb(m[c]);
					}else{
						result.pb(c);
						break;
					}
			}
			int j  = str.length()-1 , i = 0;
			while(i<j){
					if(str[i++]!=str[j--]){
						 isPalindrome = false;
					}
			}
			string str2 = result;
			reverse(all(result));
			cerr << "is Mirrod " << result << endl;
			if(result != str && isMirrored){
				isMirrored = false;
			}
			cerr << isMirrored << " " << isPalindrome << endl;
			if( isMirrored && isPalindrome){
				cout << str <<" -- " << "is a mirrored palindrome." << endl;
			}else if(isMirrored && !isPalindrome){
				cout << str << " -- " << "is a mirrored string." << endl;
			}else if(!isMirrored && isPalindrome){
				cout << str << " -- " << "is a regular palindrome." << endl;
			}else{
				cout << str << " -- " << "is not a palindrome." << endl;
			}
			 cout << endl;

		}
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
