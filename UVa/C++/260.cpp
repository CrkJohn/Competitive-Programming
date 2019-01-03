#include<bits/stdc++.h>
#define FOR(i,b) for(int i = 0; i<b;i++)
#define SZ 210
#define X first
#define Y second
using namespace std;

typedef pair<int,int> ii;

char G[SZ][SZ];
int vis[SZ][SZ];
int x[] = {0,0,1,-1,1,-1};
int y[] = {1,-1,0,0,1,-1};
int bPudo,n;

void dfsITER(ii src){
	stack<ii> way;
	way.push(src);
	ii u;
	while (!way.empty()){
		u = way.top(); way.pop();
		vis[u.X][u.Y] = 1;
		if(u.X==n-1){
			bPudo = 1;
			break;
		}
		FOR(i,6){
			int h = u.X + x[i];
			int k = u.Y + y[i];
			if(0<=h && k>=0 && h<n && k<n && !vis[h][k] && G[h][k]=='b'){
				way.push(ii(h,k));
			}
		}
	}
	return;
}

int main(){
	int ntc = 1;
	while(scanf("%d",&n),n){
        FOR(i,n)scanf("%s%*c",G[i]);
        bPudo = 0;
        vis[n+1][n+1];
		memset(vis,0,sizeof vis);
		//Solution
		FOR(i,n)if(!vis[0][i] && G[0][i]=='b' && !bPudo)dfsITER(ii(0,i));
        if(bPudo){
			printf("%d B\n",ntc++);
        }else{
			printf("%d W\n",ntc++);
        }
	}
	return 0;
}
