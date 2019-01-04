#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define forn(i,a,b) for(int i = a; i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define eps 1e-9
#define INF 1e9
#define in() freopen("in.txt","r",stdin);
#define out() freopen("out.txt","w",stdout);

using namespace std;

const int maxn = 30100;

int main(){
	//in();
	//out();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n,t;
	cin >> n >> t;
	int g[maxn];
	forn(i,1,n){
		cin >> g[i];
	}
	stack<int> st;
	st.push(1);
	int f = 1;
	while(!st.empty()){
      int u = st.top();st.pop();
      cerr << "u : " << u << endl;
      if(u>t){
				 f = 0;
				 break;
      }else if(u==t){
					break;
      }
      st.push(u+g[u]);
	}
	cout << ((f == 1 ) ? "YES" : "NO") << endl;
	return 0;

}
