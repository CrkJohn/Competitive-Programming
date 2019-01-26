#include<bits/stdc++.h>
#include<string>
#define pb push_back
#define fi first
#define se second
#define forn(i,n) for(int i = 0 ; i<n;i++)
#define for1(i,n) for(int i = 1 ; i<=n;i++)
#define fore(i,a,b) for(int i = a ; i<b;i++)
#define ford(i,n) for(int i = n ; i>=0;i--)
#define mp make_pair
#define eps 1e-9
#define INF 1e9
#define si(a) ((int)a.size())

using namespace std;


typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


struct point{
	ll x,y;
	point(){x  =  y = .0;}
	point (ll X,ll Y){
			x =X;
			y =Y;
	}
};


const int maxn = 51;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout << fixed;
	cout.precision(10);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	string str,splt;
	int f = 0, ct;
	while(cin >> n){
			getline(cin,str);
			vector<string> text;
			map<string,int> frec;
			vector<string> split;
			while(1){
					getline(cin,str);
					stringstream ss;
					ss << str;
					if(str=="EndOfText"){
						break;
					}
					while(ss >> splt){
							string result ="";
							for(auto c :  splt){
									if(c <= 'Z' && c >= 'A')c =  c - ('Z' - 'z');
									if(c<='z' && c>='a'){
											result.pb(c);
									}else{
										if(result.length()!=0){
													frec[result] = (frec.find(result)==frec.end()) ? 1 : frec[result]+1;
													if(frec[result]==n)split.pb(result);
										}
										result = "";
									}
							}
							if(result.length()!=0){
									frec[result] = (frec.find(result)==frec.end()) ? 1 : frec[result]+1;
									if(frec[result]==n)split.pb(result);
							}
          }
			}
			sort(split.begin(),split.end());
			if(f) cout << endl;
			f  =1 ,  ct = 0;
			for(auto s : split){
					if(frec[s]==n){
								cout << s << endl;
								ct = 1;
          }
			}
			if(!ct)cout << "There is no such word." << endl;
	}
	return 0;
}
