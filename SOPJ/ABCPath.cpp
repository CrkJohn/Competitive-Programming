#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int const maxn = 55;
int mat[maxn][maxn];
int vis[maxn][maxn];
	
const int dx [] = {-1, -1 , -1 , 0 , 0, 1, 1, 1} ; 
const int dy [] = {-1, 0 , 1 ,  -1  , 1, -1, 0, 1} ; 
	
	
int n,m ;
	
int bfs(pair<int,int> a){
	queue<pair<int, int> > q;
	q.push({a.fi, a.se});
	memset(vis,-1,sizeof vis);
	vis[a.fi][a.se]  = 1;
	int longest = 1;
	while(!q.empty()){
		pair<int,int>  u = q.front(); q.pop();
		for(int i = 0 ; i< 8 ; i++){
			int h = u.fi + dx[i],  k = u.se + dy[i]; 	
			if(0<=h && h <n && 0<=k && k <m && mat[h][k] == mat[u.fi][u.se]+1){
				if(vis[h][k]!= -1 )continue;
				vis[h][k] =  vis[u.fi][u.se]  + 1 ;
				longest = max(longest,vis[h][k]);
				q.push({h,k});
			}			
		}
	}	
	return longest;
}
	
	
int main(){
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in.txt","r",stdin);
	*/
	int ntc = 1;
	while(cin >> n >> m, n+m!=0){	
		string str;		
		for(int i = 0 ; i < n ; i++){
			cin >> str;
			for(int j = 0 ;j < m ; j++){
				 mat[i][j] = str[j]-'A';
			}
		}		
		memset(vis,-1,sizeof vis);
		int longest = -1e9, maax;	
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				maax = 0;
				if(mat[i][j] == 0){
					 maax = bfs({i,j});
				}
				longest = max(longest,maax);
			}
		}
		cout <<"Case "<<ntc++<<": "<<  longest << endl;
	}
	return 0;
}
