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
    cout.precision(2);
    cout << fixed;
    //in();
    //out();
		int ntc;
		cin >> ntc;
		string str;
		getline(cin,str);
		map<char,double> prefix;
		prefix['k'] = 1e3;
		prefix['m'] = 1e-3;
		prefix['M'] = 1e6;

		for1(i,ntc){
				cout <<"Problem #" << i <<endl;
				getline(cin,str);
				int idxU = str.find("U=");
				int idxI = str.find("I=");
				int idxP = str.find("P=");
				string U,I,P;
				if(idxU==-1){
					cerr << "Good " <<" " << idxP << " " << idxI <<  endl;
					int num = str.find('W',idxP+1);
					int num2 = str.find('A',idxI+1);
					string numStr =  str.substr(idxP,num-idxP);
					string numStr2 =  str.substr(idxI,num2-idxI);
					int lenSubStr2 = si(numStr2);
					int lenSubStr = si(numStr);
					cerr << numStr2 << " - " << numStr << endl;
					double I = atof(numStr2.substr(2,si(numStr2)-2).c_str());
					if(!('0'<=numStr2[lenSubStr2-1] && numStr2[lenSubStr2-1]<='9' && numStr2[lenSubStr2-1]!='A')){
//						 cerr << "Entre :)" << endl;

						 I *= (prefix[numStr2[lenSubStr2-1]]);
					}
					double P  = atof(numStr.substr(2,si(numStr)-2).c_str());
//					cerr << " p : " << P << numStr << endl;
					if(!('0'<=numStr[lenSubStr-1] && numStr[lenSubStr-1]<='9' && numStr[lenSubStr-1]!='W')){
						 P *= (prefix[numStr[lenSubStr-1]]);
					}
					cout <<"U=" <<P/I<<"V"<< endl;
//					cerr << " I : " << I  <<" p : " << P << endl;
				}else if(idxI==-1){
					int num3 = str.find('V',idxU+1);
					int num = str.find('W',idxP+1);
					string numStr =  str.substr(idxU,num3-idxU);
					string numStr2 =  str.substr(idxP,num-idxP);
					int lenSubStr2 = si(numStr2);
					double P = atof(numStr2.substr(2,si(numStr2)-2).c_str());
					if(!('0'<=numStr2[lenSubStr2-1] && numStr2[lenSubStr2-1]<='9' && numStr2[lenSubStr2-1]!='W' )){
						 P *= (prefix[numStr2[lenSubStr2-1]]);
					}
					double U  = atof(numStr.substr(2,si(numStr)-2).c_str());
					int lenSubStr = si(numStr);
					if(!('0'<=numStr[lenSubStr-1] && numStr[lenSubStr-1]<='9')){
						 U *= (prefix[numStr[lenSubStr-1]]);
					}

					cout << "I="<<(P/U)<<"A"<< endl;
//					cerr << " P : " << P << " U : " << U << endl;

				}else{
						int num2 = str.find('A',idxI+1);
						int num3 = str.find('V',idxU+1);
						string numStr =  str.substr(idxI,num2-idxI);
						string numStr2 =  str.substr(idxU,num3-idxU);
						double U = atof(numStr2.substr(2,si(numStr2)-2).c_str());
//						cerr << " u : " << U << " " << numStr2 << endl;
						int lenSubStr2 = si(numStr2);
						if(!('0'<=numStr2[lenSubStr2-1] && numStr2[lenSubStr2-1]<='9' &&  numStr2[lenSubStr2-1]!='V')){
							  U  *= (prefix[numStr2[lenSubStr2-1]]);
						}
						int lenSubStr = si(numStr);
						double I  = atof(numStr.substr(2,si(numStr)-2).c_str());

						if(!('0'<=numStr[lenSubStr-1] && numStr[lenSubStr-1]<='9'  )){
								I*=(prefix[numStr[lenSubStr-1]]);
						}
						cout <<"P="<<  U*I <<"W"<< endl;
//						cerr << " U : " << U << " I : " << I << endl;
				}
				cout << endl;


		}

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
