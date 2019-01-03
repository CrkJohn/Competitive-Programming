#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define FOR(i,b) for(int i = 0 ; i < b ; i++)
#define loop(i,a,b) for(int i = a ; i < b ; i++)

using namespace std;

typedef vector<int> vi ;
typedef vector<vi> vii;

const int LIM =  1010;

vii G;
int n, m, p[LIM], lo[LIM], num[LIM], dfscount, SCC,vis[LIM];
stack<int> s;


void tarjan(int u){
	int v;
	lo[u]=num[u]= dfscount++;
	s.push(u);
	vis[u]=true;
	loop(j, 0, (int)G[u].size()){
		v=G[u][j];
		if (num[v]==0) tarjan(v);
		if (vis[v]) lo[u]=min(lo[u], lo[v]);
	}
	if (lo[u]==num[u]){
		//printf("SCC=%d\n", SCC);
		do{
			v=s.top(); s.pop();
			//printf("%d\n", v+1);
			vis[v]=0;
			p[v]=SCC;
		}while (u!=v);
		SCC++;
	}
}

int main(){

	int Cp;int u,v,U; int n,e;
    map<string,int> Ind;//identifica
    while(scanf("%d %d",&n,&e),n+e){
		Ind.clear();Cp = SCC =   0 ;G.clear();
		G.assign(n,vi());
		FOR(i,e){
				scanf("%d %d %d",&u,&v,&U);
				if(U==2)G[v-1].pb(u-1);
				G[u-1].pb(v-1);
		}

		loop(i, 0, n) num[i]=lo[i]=0, vis[i]=0;
		dfscount=1;
		loop(i, 0, n){
			if (num[i]==0) tarjan(i);
		}
		char r = (SCC==1)? '1' : '0';
		printf("%c\n",r);
    }
	return 0;
}
