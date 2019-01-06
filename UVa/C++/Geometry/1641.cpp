#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define FOR(i,b) for(int i = 0; i<b;i++)
#define forn(i,a,b) for(int i = a; i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define eps 1e-9
#define INF 1e9
#define lec() freopen("in.txt","r",stdin);	freopen("err.txt","w",stderr); freopen("out.txt","w",stdout)

using namespace std;


int dx[] = {0,1} , dy[]  = {1,0};

int main(){
	//lec();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	//1641 - ASCII Area
	char table[200][200];
	while(1){
			int n,m;
			cin >> n >>m;
			if(cin.eof())break;
			FOR(i,n){
					FOR(j,m){
							cin >> table[i][j];
					}
			}
			int I = 0 ,B = 0;
			int  vis[n][m];
			memset(vis,0,sizeof vis);
			FOR(i,n){
					int j = 0;
					while(j<m){
							if(table[i][j]=='\\' || table[i][j]=='/'){
									B++;
									j++;
									while(j<m){
											if(table[i][j]=='/' || table[i][j]=='\\'){
													B++;
													break;
											}
											j++;
											I++;
								 }
							}
						j++;
					}
			}
 			cout <<  I + B/2 << endl;
  }

	return 0;
}
